#include "clinique.h"

// Fonction pour afficher le menu principal
void afficher_menu_principal() {
    nettoyer_ecran();
    afficher_banniere();
    
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                        MENU PRINCIPAL                       ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    printf("Bienvenue %s %s (%s)\n\n", 
           utilisateur_courant->prenom, 
           utilisateur_courant->nom,
           utilisateur_courant->type == 1 ? "Gestionnaire" : "Secrétaire");
    
    printf("Appuyez sur Entrée pour continuer...");
    getchar();
}

// Fonction pour afficher le menu du gestionnaire
void afficher_menu_gestionnaire() {
    int choix;
    
    do {
        nettoyer_ecran();
        afficher_banniere();
        
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                    MENU GESTIONNAIRE                        ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n\n");
        
        printf("Utilisateur: %s %s (Gestionnaire)\n\n", 
               utilisateur_courant->prenom, utilisateur_courant->nom);
        
        printf("1.  Créer un nouvel utilisateur\n");
        printf("2.  Gérer les médecins\n");
        printf("3.  Gérer les spécialités\n");
        printf("4.  Gérer les patients\n");
        printf("5.  Gérer les rendez-vous\n");
        printf("6.  Lister les médecins disponibles\n");
        printf("7.  Lister les rendez-vous en cours\n");
        printf("8.  Lister les patients avec rendez-vous\n");
        printf("9.  Filtrer les rendez-vous par statut\n");
        printf("10. Enregistrer un rendez-vous\n");
        printf("11. Libérer un médecin\n");
        printf("12. Changer mon mot de passe\n");
        printf("13. Sauvegarder les données\n");
        printf("0.  Déconnexion\n\n");
        
        printf("Votre choix: ");
        choix = lire_entier();
        
        switch (choix) {
            case 1:
                creer_utilisateur();
                break;
            case 2:
                gerer_medecins();
                break;
            case 3:
                gerer_specialites();
                break;
            case 4:
                gerer_patients();
                break;
            case 5:
                gerer_rendezvous();
                break;
            case 6:
                lister_medecins_disponibles();
                break;
            case 7:
                lister_rendezvous_en_cours();
                break;
            case 8:
                lister_patients_avec_rdv();
                break;
            case 9:
                filtrer_rendezvous_par_statut();
                break;
            case 10:
                enregistrer_rendezvous();
                break;
            case 11:
                liberer_medecin();
                break;
            case 12:
                changer_mot_de_passe();
                break;
            case 13:
                sauvegarder_donnees();
                break;
            case 0:
                if (confirmer_action("Voulez-vous vraiment vous déconnecter ?")) {
                    utilisateur_courant = NULL;
                    afficher_info("Déconnexion réussie.");
                    faire_pause();
                }
                break;
            default:
                afficher_erreur("Choix invalide.");
                faire_pause();
        }
        
    } while (choix != 0);
}

// Fonction pour afficher le menu du secrétaire
void afficher_menu_secretaire() {
    int choix;
    
    do {
        nettoyer_ecran();
        afficher_banniere();
        
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                      MENU SECRÉTAIRE                        ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n\n");
        
        printf("Utilisateur: %s %s (Secrétaire)\n\n", 
               utilisateur_courant->prenom, utilisateur_courant->nom);
        
        printf("1.  Vérifier la disponibilité des médecins\n");
        printf("2.  Lister les patients avec rendez-vous\n");
        printf("3.  Filtrer les rendez-vous par statut\n");
        printf("4.  Enregistrer un rendez-vous\n");
        printf("5.  Libérer un médecin\n");
        printf("6.  Changer mon mot de passe\n");
        printf("0.  Déconnexion\n\n");
        
        printf("Votre choix: ");
        choix = lire_entier();
        
        switch (choix) {
            case 1:
                lister_medecins_disponibles();
                break;
            case 2:
                lister_patients_avec_rdv();
                break;
            case 3:
                filtrer_rendezvous_par_statut();
                break;
            case 4:
                enregistrer_rendezvous();
                break;
            case 5:
                liberer_medecin();
                break;
            case 6:
                changer_mot_de_passe();
                break;
            case 0:
                if (confirmer_action("Voulez-vous vraiment vous déconnecter ?")) {
                    utilisateur_courant = NULL;
                    afficher_info("Déconnexion réussie.");
                    faire_pause();
                }
                break;
            default:
                afficher_erreur("Choix invalide.");
                faire_pause();
        }
        
    } while (choix != 0);
}

// Fonction pour afficher un tableau de médecins
void afficher_tableau_medecins() {
    printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-5s │ %-15s │ %-8s │ %-15s │ %-20s │ %-10s ║\n", "ID", "Matricule", "Cabinet", "Spécialité", "Nom", "Statut");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_medecins; i++) {
        printf("║ %-5d │ %-15s │ %-8d │ %-15s │ %-20s │ %-10s ║\n",
               medecins[i].id,
               medecins[i].matricule,
               medecins[i].numero_cabinet,
               medecins[i].specialite,
               "Dr. Nom", // À compléter quand on aura les noms des médecins
               medecins[i].etat ? "Actif" : "Inactif");
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

// Fonction pour afficher un tableau de spécialités
void afficher_tableau_specialites() {
    printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-5s │ %-10s │ %-20s │ %-50s ║\n", "ID", "Code", "Libellé", "Description");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_specialites; i++) {
        printf("║ %-5d │ %-10s │ %-20s │ %-50s ║\n",
               specialites[i].id,
               specialites[i].code,
               specialites[i].libelle,
               specialites[i].description);
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

// Fonction pour afficher un tableau de patients
void afficher_tableau_patients() {
    printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-5s │ %-20s │ %-20s │ %-30s │ %-15s ║\n", "ID", "Nom", "Prénom", "Adresse", "Téléphone");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_patients; i++) {
        printf("║ %-5d │ %-20s │ %-20s │ %-30s │ %-15s ║\n",
               patients[i].id,
               patients[i].nom,
               patients[i].prenom,
               patients[i].adresse,
               patients[i].telephone);
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

// Fonction pour afficher un tableau de rendez-vous
void afficher_tableau_rendezvous() {
    printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-5s │ %-20s │ %-8s │ %-12s │ %-20s │ %-10s ║\n", "ID", "Numéro", "Médecin", "Date", "Patient", "Statut");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_rendezvous; i++) {
        printf("║ %-5d │ %-20s │ %-8d │ %-12s │ %-20s │ %-10s ║\n",
               rendezvous[i].id,
               rendezvous[i].numero,
               rendezvous[i].id_medecin,
               rendezvous[i].date,
               rendezvous[i].nom_patient,
               rendezvous[i].statut ? "Actif" : "Inactif");
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}