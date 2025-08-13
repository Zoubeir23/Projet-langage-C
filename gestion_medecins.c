#include "clinique.h"

// Fonction pour gérer les médecins
void gerer_medecins() {
    if (utilisateur_courant == NULL || utilisateur_courant->type != 1) {
        afficher_erreur("Accès refusé. Seuls les gestionnaires peuvent gérer les médecins.");
        return;
    }
    
    int choix;
    
    do {
        nettoyer_ecran();
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                    GESTION DES MÉDECINS                     ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n\n");
        
        printf("1.  Créer un nouveau médecin\n");
        printf("2.  Modifier un médecin\n");
        printf("3.  Archiver un médecin\n");
        printf("4.  Lister tous les médecins\n");
        printf("0.  Retour au menu principal\n\n");
        
        printf("Votre choix: ");
        choix = lire_entier();
        
        switch (choix) {
            case 1:
                creer_medecin();
                break;
            case 2:
                modifier_medecin();
                break;
            case 3:
                archiver_medecin();
                break;
            case 4:
                lister_tous_medecins();
                break;
            case 0:
                return;
            default:
                afficher_erreur("Choix invalide.");
                faire_pause();
        }
        
    } while (choix != 0);
}

// Fonction pour créer un nouveau médecin
void creer_medecin() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    CRÉATION D'UN MÉDECIN                     ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_medecins >= MAX_MEDECINS) {
        afficher_erreur("Nombre maximum de médecins atteint.");
        faire_pause();
        return;
    }
    
    if (nb_specialites == 0) {
        afficher_erreur("Aucune spécialité n'est disponible. Veuillez d'abord créer des spécialités.");
        faire_pause();
        return;
    }
    
    Medecin nouveau_medecin;
    nouveau_medecin.id = nb_medecins + 1;
    
    // Saisie des informations
    printf("Numéro de cabinet: ");
    nouveau_medecin.numero_cabinet = lire_entier();
    
    if (nouveau_medecin.numero_cabinet <= 0) {
        afficher_erreur("Numéro de cabinet invalide.");
        faire_pause();
        return;
    }
    
    // Choix de la spécialité
    printf("\nSpécialités disponibles:\n");
    for (int i = 0; i < nb_specialites; i++) {
        printf("%d. %s - %s\n", i + 1, specialites[i].code, specialites[i].libelle);
    }
    
    printf("Choix de la spécialité (1-%d): ", nb_specialites);
    int choix_specialite = lire_entier();
    
    if (choix_specialite < 1 || choix_specialite > nb_specialites) {
        afficher_erreur("Choix de spécialité invalide.");
        faire_pause();
        return;
    }
    
    strcpy(nouveau_medecin.specialite, specialites[choix_specialite - 1].libelle);
    
    // Génération automatique du matricule
    strcpy(nouveau_medecin.matricule, generer_matricule(specialites[choix_specialite - 1].code, nouveau_medecin.id));
    
    nouveau_medecin.etat = 1; // Actif par défaut
    
    // Ajouter le médecin
    medecins[nb_medecins++] = nouveau_medecin;
    
    afficher_succes("Médecin créé avec succès !");
    printf("Matricule généré: %s\n", nouveau_medecin.matricule);
    
    faire_pause();
}

// Fonction pour modifier un médecin
void modifier_medecin() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    MODIFICATION D'UN MÉDECIN                  ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_medecins == 0) {
        afficher_info("Aucun médecin à modifier.");
        faire_pause();
        return;
    }
    
    lister_tous_medecins();
    
    printf("\nEntrez l'ID du médecin à modifier: ");
    int id = lire_entier();
    
    if (id <= 0 || id > nb_medecins) {
        afficher_erreur("ID de médecin invalide.");
        faire_pause();
        return;
    }
    
    Medecin* medecin = &medecins[id - 1];
    
    printf("\nMédecin sélectionné: %s (Spécialité: %s)\n", medecin->matricule, medecin->specialite);
    
    printf("Nouveau numéro de cabinet (actuel: %d): ", medecin->numero_cabinet);
    int nouveau_cabinet = lire_entier();
    
    if (nouveau_cabinet > 0) {
        medecin->numero_cabinet = nouveau_cabinet;
    }
    
    printf("Changer la spécialité ? (o/n): ");
    char reponse;
    scanf(" %c", &reponse);
    getchar();
    
    if (reponse == 'o' || reponse == 'O') {
        printf("\nSpécialités disponibles:\n");
        for (int i = 0; i < nb_specialites; i++) {
            printf("%d. %s - %s\n", i + 1, specialites[i].code, specialites[i].libelle);
        }
        
        printf("Nouvelle spécialité (1-%d): ", nb_specialites);
        int choix_specialite = lire_entier();
        
        if (choix_specialite >= 1 && choix_specialite <= nb_specialites) {
            strcpy(medecin->specialite, specialites[choix_specialite - 1].libelle);
            // Régénérer le matricule
            strcpy(medecin->matricule, generer_matricule(specialites[choix_specialite - 1].code, medecin->id));
        }
    }
    
    afficher_succes("Médecin modifié avec succès !");
    faire_pause();
}

// Fonction pour archiver un médecin
void archiver_medecin() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    ARCHIVAGE D'UN MÉDECIN                    ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_medecins == 0) {
        afficher_info("Aucun médecin à archiver.");
        faire_pause();
        return;
    }
    
    lister_tous_medecins();
    
    printf("\nEntrez l'ID du médecin à archiver: ");
    int id = lire_entier();
    
    if (id <= 0 || id > nb_medecins) {
        afficher_erreur("ID de médecin invalide.");
        faire_pause();
        return;
    }
    
    Medecin* medecin = &medecins[id - 1];
    
    if (medecin->etat == 0) {
        afficher_info("Ce médecin est déjà archivé.");
        faire_pause();
        return;
    }
    
    printf("Médecin sélectionné: %s (Spécialité: %s)\n", medecin->matricule, medecin->specialite);
    
    if (confirmer_action("Voulez-vous vraiment archiver ce médecin ?")) {
        medecin->etat = 0;
        afficher_succes("Médecin archivé avec succès !");
    }
    
    faire_pause();
}

// Fonction pour lister tous les médecins
void lister_tous_medecins() {
    printf("\nListe des médecins:\n");
    afficher_tableau_medecins();
}

// Fonction pour gérer les spécialités
void gerer_specialites() {
    if (utilisateur_courant == NULL || utilisateur_courant->type != 1) {
        afficher_erreur("Accès refusé. Seuls les gestionnaires peuvent gérer les spécialités.");
        return;
    }
    
    int choix;
    
    do {
        nettoyer_ecran();
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                  GESTION DES SPÉCIALITÉS                   ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n\n");
        
        printf("1.  Créer une nouvelle spécialité\n");
        printf("2.  Modifier une spécialité\n");
        printf("3.  Lister toutes les spécialités\n");
        printf("0.  Retour au menu principal\n\n");
        
        printf("Votre choix: ");
        choix = lire_entier();
        
        switch (choix) {
            case 1:
                creer_specialite();
                break;
            case 2:
                modifier_specialite();
                break;
            case 3:
                lister_toutes_specialites();
                break;
            case 0:
                return;
            default:
                afficher_erreur("Choix invalide.");
                faire_pause();
        }
        
    } while (choix != 0);
}

// Fonction pour créer une nouvelle spécialité
void creer_specialite() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                  CRÉATION D'UNE SPÉCIALITÉ                   ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_specialites >= MAX_SPECIALITES) {
        afficher_erreur("Nombre maximum de spécialités atteint (3 maximum).");
        faire_pause();
        return;
    }
    
    Specialite nouvelle_specialite;
    nouvelle_specialite.id = nb_specialites + 1;
    
    // Saisie des informations
    printf("Code de la spécialité: ");
    lire_chaine(nouvelle_specialite.code, sizeof(nouvelle_specialite.code));
    
    printf("Libellé de la spécialité: ");
    lire_chaine(nouvelle_specialite.libelle, sizeof(nouvelle_specialite.libelle));
    
    printf("Description de la spécialité: ");
    lire_chaine(nouvelle_specialite.description, sizeof(nouvelle_specialite.description));
    
    // Ajouter la spécialité
    specialites[nb_specialites++] = nouvelle_specialite;
    
    afficher_succes("Spécialité créée avec succès !");
    faire_pause();
}

// Fonction pour modifier une spécialité
void modifier_specialite() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                MODIFICATION D'UNE SPÉCIALITÉ                 ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_specialites == 0) {
        afficher_info("Aucune spécialité à modifier.");
        faire_pause();
        return;
    }
    
    lister_toutes_specialites();
    
    printf("\nEntrez l'ID de la spécialité à modifier: ");
    int id = lire_entier();
    
    if (id <= 0 || id > nb_specialites) {
        afficher_erreur("ID de spécialité invalide.");
        faire_pause();
        return;
    }
    
    Specialite* specialite = &specialites[id - 1];
    
    printf("\nSpécialité sélectionnée: %s - %s\n", specialite->code, specialite->libelle);
    
    printf("Nouveau libellé: ");
    lire_chaine(specialite->libelle, sizeof(specialite->libelle));
    
    printf("Nouvelle description: ");
    lire_chaine(specialite->description, sizeof(specialite->description));
    
    afficher_succes("Spécialité modifiée avec succès !");
    faire_pause();
}

// Fonction pour lister toutes les spécialités
void lister_toutes_specialites() {
    printf("\nListe des spécialités:\n");
    afficher_tableau_specialites();
}