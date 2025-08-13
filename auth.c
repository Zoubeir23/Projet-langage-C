#include "clinique.h"

// Fonction d'initialisation du système
void initialiser_systeme() {
    // Créer le dossier RENDEZVOUS s'il n'existe pas
    system("mkdir -p RENDEZVOUS");
    
    // Initialiser les compteurs
    nb_specialites = 0;
    nb_medecins = 0;
    nb_users = 0;
    nb_patients = 0;
    nb_rendezvous = 0;
    utilisateur_courant = NULL;
    
    // Créer un utilisateur gestionnaire par défaut s'il n'existe pas
    if (nb_users == 0) {
        Utilisateur admin;
        admin.id = 1;
        strcpy(admin.nom, "ADMIN");
        strcpy(admin.prenom, "System");
        strcpy(admin.telephone, "0000000000");
        strcpy(admin.email, "as2025@satanksamatank.sn");
        strcpy(admin.login, "ADMIN");
        strcpy(admin.mot_de_passe, "passerstst");
        admin.type = 1; // Gestionnaire
        admin.premier_connexion = 0;
        
        users[nb_users++] = admin;
        afficher_info("Utilisateur administrateur créé par défaut (login: ADMIN, mot de passe: passerstst)");
    }
}

// Fonction de connexion
void connexion() {
    nettoyer_ecran();
    afficher_banniere();
    
    char login[LOGIN_LENGTH + 1];
    char mot_de_passe[PASSWORD_LENGTH + 1];
    char mot_crypte[PASSWORD_LENGTH + 1];
    
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                        CONNEXION                            ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    // Demander le login
    printf("Login (5 caractères majuscules): ");
    lire_chaine(login, sizeof(login));
    
    if (!valider_login(login)) {
        afficher_erreur("Format de login invalide. Le login doit contenir exactement 5 caractères alphabétiques majuscules.");
        faire_pause();
        return;
    }
    
    // Demander le mot de passe
    printf("Mot de passe: ");
    lire_chaine(mot_de_passe, sizeof(mot_de_passe));
    
    // Vérifier les identifiants
    for (int i = 0; i < nb_users; i++) {
        if (strcmp(users[i].login, login) == 0) {
            // Décrypter le mot de passe stocké
            decrypter_mot_de_passe(users[i].mot_de_passe, mot_crypte);
            
            if (strcmp(mot_de_passe, mot_crypte) == 0) {
                utilisateur_courant = &users[i];
                afficher_succes("Connexion réussie !");
                faire_pause();
                return;
            }
        }
    }
    
    afficher_erreur("Login ou mot de passe incorrect.");
    faire_pause();
}

// Fonction pour créer un nouvel utilisateur (réservée au gestionnaire)
void creer_utilisateur() {
    if (utilisateur_courant == NULL || utilisateur_courant->type != 1) {
        afficher_erreur("Accès refusé. Seuls les gestionnaires peuvent créer des utilisateurs.");
        return;
    }
    
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    CRÉATION D'UTILISATEUR                   ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_users >= MAX_USERS) {
        afficher_erreur("Nombre maximum d'utilisateurs atteint.");
        faire_pause();
        return;
    }
    
    Utilisateur nouvel_user;
    nouvel_user.id = nb_users + 1;
    
    // Saisie des informations
    printf("Nom: ");
    lire_chaine(nouvel_user.nom, sizeof(nouvel_user.nom));
    
    printf("Prénom: ");
    lire_chaine(nouvel_user.prenom, sizeof(nouvel_user.prenom));
    
    printf("Téléphone: ");
    lire_chaine(nouvel_user.telephone, sizeof(nouvel_user.telephone));
    
    // Génération automatique de l'email
    strcpy(nouvel_user.email, generer_email(nouvel_user.nom, obtenir_annee_actuelle()));
    printf("Email généré: %s\n", nouvel_user.email);
    
    // Saisie du login
    do {
        printf("Login (5 caractères majuscules): ");
        lire_chaine(nouvel_user.login, sizeof(nouvel_user.login));
        
        if (!valider_login(nouvel_user.login)) {
            afficher_erreur("Format de login invalide. Le login doit contenir exactement 5 caractères alphabétiques majuscules.");
            continue;
        }
        
        // Vérifier que le login n'existe pas déjà
        int login_existe = 0;
        for (int i = 0; i < nb_users; i++) {
            if (strcmp(users[i].login, nouvel_user.login) == 0) {
                login_existe = 1;
                break;
            }
        }
        
        if (login_existe) {
            afficher_erreur("Ce login existe déjà. Veuillez en choisir un autre.");
            continue;
        }
        
        break;
    } while (1);
    
    // Mot de passe par défaut
    strcpy(nouvel_user.mot_de_passe, DEFAULT_PASSWORD);
    printf("Mot de passe par défaut: %s\n", DEFAULT_PASSWORD);
    
    // Type d'utilisateur
    printf("Type d'utilisateur:\n");
    printf("1. Gestionnaire\n");
    printf("2. Secrétaire\n");
    printf("Choix: ");
    nouvel_user.type = lire_entier();
    
    if (nouvel_user.type != 1 && nouvel_user.type != 2) {
        nouvel_user.type = 2; // Par défaut, secrétaire
    }
    
    nouvel_user.premier_connexion = 1; // Doit changer le mot de passe
    
    // Crypter le mot de passe
    char mot_crypte[PASSWORD_LENGTH + 1];
    crypter_mot_de_passe(nouvel_user.mot_de_passe, mot_crypte);
    strcpy(nouvel_user.mot_de_passe, mot_crypte);
    
    // Ajouter l'utilisateur
    users[nb_users++] = nouvel_user;
    
    afficher_succes("Utilisateur créé avec succès !");
    printf("L'utilisateur devra changer son mot de passe lors de sa première connexion.\n");
    
    faire_pause();
}

// Fonction pour changer le mot de passe
void changer_mot_de_passe() {
    if (utilisateur_courant == NULL) {
        return;
    }
    
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                  CHANGEMENT DE MOT DE PASSE                 ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    printf("Bonjour %s %s,\n", utilisateur_courant->prenom, utilisateur_courant->nom);
    
    if (utilisateur_courant->premier_connexion) {
        printf("C'est votre première connexion. Vous devez changer votre mot de passe.\n\n");
    } else {
        printf("Vous allez changer votre mot de passe.\n\n");
    }
    
    char ancien_mot_de_passe[PASSWORD_LENGTH + 1];
    char nouveau_mot_de_passe[PASSWORD_LENGTH + 1];
    char confirmation[PASSWORD_LENGTH + 1];
    char mot_crypte[PASSWORD_LENGTH + 1];
    
    // Vérifier l'ancien mot de passe
    if (!utilisateur_courant->premier_connexion) {
        printf("Ancien mot de passe: ");
        lire_chaine(ancien_mot_de_passe, sizeof(ancien_mot_de_passe));
        
        decrypter_mot_de_passe(utilisateur_courant->mot_de_passe, mot_crypte);
        if (strcmp(ancien_mot_de_passe, mot_crypte) != 0) {
            afficher_erreur("Ancien mot de passe incorrect.");
            faire_pause();
            return;
        }
    }
    
    // Saisir le nouveau mot de passe
    do {
        printf("Nouveau mot de passe: ");
        lire_chaine(nouveau_mot_de_passe, sizeof(nouveau_mot_de_passe));
        
        if (strlen(nouveau_mot_de_passe) < 6) {
            afficher_erreur("Le mot de passe doit contenir au moins 6 caractères.");
            continue;
        }
        
        printf("Confirmer le nouveau mot de passe: ");
        lire_chaine(confirmation, sizeof(confirmation));
        
        if (strcmp(nouveau_mot_de_passe, confirmation) != 0) {
            afficher_erreur("Les mots de passe ne correspondent pas.");
            continue;
        }
        
        break;
    } while (1);
    
    // Crypter et sauvegarder le nouveau mot de passe
    crypter_mot_de_passe(nouveau_mot_de_passe, mot_crypte);
    strcpy(utilisateur_courant->mot_de_passe, mot_crypte);
    utilisateur_courant->premier_connexion = 0;
    
    afficher_succes("Mot de passe changé avec succès !");
    faire_pause();
}