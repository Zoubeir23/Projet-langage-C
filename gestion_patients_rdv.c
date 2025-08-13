#include "clinique.h"

// Fonction pour gérer les patients
void gerer_patients() {
    if (utilisateur_courant == NULL || utilisateur_courant->type != 1) {
        afficher_erreur("Accès refusé. Seuls les gestionnaires peuvent gérer les patients.");
        return;
    }
    
    int choix;
    
    do {
        nettoyer_ecran();
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                    GESTION DES PATIENTS                      ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n\n");
        
        printf("1.  Créer un nouveau patient\n");
        printf("2.  Modifier un patient\n");
        printf("3.  Lister tous les patients\n");
        printf("0.  Retour au menu principal\n\n");
        
        printf("Votre choix: ");
        choix = lire_entier();
        
        switch (choix) {
            case 1:
                creer_patient();
                break;
            case 2:
                modifier_patient();
                break;
            case 3:
                lister_tous_patients();
                break;
            case 0:
                return;
            default:
                afficher_erreur("Choix invalide.");
                faire_pause();
        }
        
    } while (choix != 0);
}

// Fonction pour créer un nouveau patient
void creer_patient() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    CRÉATION D'UN PATIENT                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_patients >= MAX_PATIENTS) {
        afficher_erreur("Nombre maximum de patients atteint.");
        faire_pause();
        return;
    }
    
    Patient nouveau_patient;
    nouveau_patient.id = nb_patients + 1;
    
    // Saisie des informations
    printf("Nom du patient: ");
    lire_chaine(nouveau_patient.nom, sizeof(nouveau_patient.nom));
    
    printf("Prénom du patient: ");
    lire_chaine(nouveau_patient.prenom, sizeof(nouveau_patient.prenom));
    
    printf("Adresse du patient: ");
    lire_chaine(nouveau_patient.adresse, sizeof(nouveau_patient.adresse));
    
    printf("Téléphone du patient: ");
    lire_chaine(nouveau_patient.telephone, sizeof(nouveau_patient.telephone));
    
    // Ajouter le patient
    patients[nb_patients++] = nouveau_patient;
    
    afficher_succes("Patient créé avec succès !");
    faire_pause();
}

// Fonction pour modifier un patient
void modifier_patient() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                  MODIFICATION D'UN PATIENT                    ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_patients == 0) {
        afficher_info("Aucun patient à modifier.");
        faire_pause();
        return;
    }
    
    lister_tous_patients();
    
    printf("\nEntrez l'ID du patient à modifier: ");
    int id = lire_entier();
    
    if (id <= 0 || id > nb_patients) {
        afficher_erreur("ID de patient invalide.");
        faire_pause();
        return;
    }
    
    Patient* patient = &patients[id - 1];
    
    printf("\nPatient sélectionné: %s %s\n", patient->prenom, patient->nom);
    
    printf("Nouveau nom: ");
    lire_chaine(patient->nom, sizeof(patient->nom));
    
    printf("Nouveau prénom: ");
    lire_chaine(patient->prenom, sizeof(patient->prenom));
    
    printf("Nouvelle adresse: ");
    lire_chaine(patient->adresse, sizeof(patient->adresse));
    
    printf("Nouveau téléphone: ");
    lire_chaine(patient->telephone, sizeof(patient->telephone));
    
    afficher_succes("Patient modifié avec succès !");
    faire_pause();
}

// Fonction pour lister tous les patients
void lister_tous_patients() {
    printf("\nListe des patients:\n");
    afficher_tableau_patients();
}

// Fonction pour gérer les rendez-vous
void gerer_rendezvous() {
    if (utilisateur_courant == NULL || utilisateur_courant->type != 1) {
        afficher_erreur("Accès refusé. Seuls les gestionnaires peuvent gérer les rendez-vous.");
        return;
    }
    
    int choix;
    
    do {
        nettoyer_ecran();
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                  GESTION DES RENDEZ-VOUS                    ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n\n");
        
        printf("1.  Lister tous les rendez-vous\n");
        printf("2.  Filtrer les rendez-vous par statut\n");
        printf("3.  Annuler un rendez-vous\n");
        printf("0.  Retour au menu principal\n\n");
        
        printf("Votre choix: ");
        choix = lire_entier();
        
        switch (choix) {
            case 1:
                lister_tous_rendezvous();
                break;
            case 2:
                filtrer_rendezvous_par_statut();
                break;
            case 3:
                annuler_rendezvous();
                break;
            case 0:
                return;
            default:
                afficher_erreur("Choix invalide.");
                faire_pause();
        }
        
    } while (choix != 0);
}

// Fonction pour lister tous les rendez-vous
void lister_tous_rendezvous() {
    printf("\nListe de tous les rendez-vous:\n");
    afficher_tableau_rendezvous();
    faire_pause();
}

// Fonction pour lister les médecins disponibles
void lister_medecins_disponibles() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                  MÉDECINS DISPONIBLES                        ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_medecins == 0) {
        afficher_info("Aucun médecin disponible.");
        faire_pause();
        return;
    }
    
    printf("Médecins actifs:\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-5s │ %-15s │ %-8s │ %-15s │ %-10s ║\n", "ID", "Matricule", "Cabinet", "Spécialité", "Statut");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_medecins; i++) {
        if (medecins[i].etat == 1) {
            printf("║ %-5d │ %-15s │ %-8d │ %-15s │ %-10s ║\n",
                   medecins[i].id,
                   medecins[i].matricule,
                   medecins[i].numero_cabinet,
                   medecins[i].specialite,
                   "Actif");
        }
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    
    faire_pause();
}

// Fonction pour lister les rendez-vous en cours
void lister_rendezvous_en_cours() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                  RENDEZ-VOUS EN COURS                        ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_rendezvous == 0) {
        afficher_info("Aucun rendez-vous en cours.");
        faire_pause();
        return;
    }
    
    printf("Rendez-vous actifs:\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-5s │ %-20s │ %-8s │ %-12s │ %-20s ║\n", "ID", "Numéro", "Médecin", "Date", "Patient");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_rendezvous; i++) {
        if (rendezvous[i].statut == 1) {
            printf("║ %-5d │ %-20s │ %-8d │ %-12s │ %-20s ║\n",
                   rendezvous[i].id,
                   rendezvous[i].numero,
                   rendezvous[i].id_medecin,
                   rendezvous[i].date,
                   rendezvous[i].nom_patient);
        }
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    
    faire_pause();
}

// Fonction pour lister les patients avec rendez-vous
void lister_patients_avec_rdv() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                PATIENTS AVEC RENDEZ-VOUS                     ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_rendezvous == 0) {
        afficher_info("Aucun patient avec rendez-vous.");
        faire_pause();
        return;
    }
    
    printf("Patients ayant des rendez-vous actifs:\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-20s │ %-20s │ %-15s │ %-12s │ %-20s ║\n", "Nom", "Prénom", "Téléphone", "Date RDV", "Médecin");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_rendezvous; i++) {
        if (rendezvous[i].statut == 1) {
            // Trouver le patient
            Patient* patient = NULL;
            for (int j = 0; j < nb_patients; j++) {
                if (strcmp(patients[j].nom, rendezvous[i].nom_patient) == 0 &&
                    strcmp(patients[j].prenom, rendezvous[i].prenom_patient) == 0) {
                    patient = &patients[j];
                    break;
                }
            }
            
            // Trouver le médecin
            Medecin* medecin = NULL;
            for (int j = 0; j < nb_medecins; j++) {
                if (medecins[j].id == rendezvous[i].id_medecin) {
                    medecin = &medecins[j];
                    break;
                }
            }
            
            printf("║ %-20s │ %-20s │ %-15s │ %-12s │ %-20s ║\n",
                   patient ? patient->nom : "N/A",
                   patient ? patient->prenom : "N/A",
                   patient ? patient->telephone : "N/A",
                   rendezvous[i].date,
                   medecin ? medecin->specialite : "N/A");
        }
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    
    faire_pause();
}

// Fonction pour filtrer les rendez-vous par statut
void filtrer_rendezvous_par_statut() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║              FILTRAGE DES RENDEZ-VOUS PAR STATUT              ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    printf("1. Rendez-vous actifs\n");
    printf("2. Rendez-vous inactifs/annulés\n");
    printf("Votre choix: ");
    
    int choix = lire_entier();
    
    if (choix != 1 && choix != 2) {
        afficher_erreur("Choix invalide.");
        faire_pause();
        return;
    }
    
    int statut_recherche = (choix == 1) ? 1 : 0;
    
    printf("\nRendez-vous %s:\n", statut_recherche ? "actifs" : "inactifs");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-5s │ %-20s │ %-8s │ %-12s │ %-20s │ %-20s ║\n", "ID", "Numéro", "Médecin", "Date", "Patient", "Motif");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_rendezvous; i++) {
        if (rendezvous[i].statut == statut_recherche) {
            printf("║ %-5d │ %-20s │ %-8d │ %-12s │ %-20s │ %-20s ║\n",
                   rendezvous[i].id,
                   rendezvous[i].numero,
                   rendezvous[i].id_medecin,
                   rendezvous[i].date,
                   rendezvous[i].nom_patient,
                   rendezvous[i].motif);
        }
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    
    faire_pause();
}

// Fonction pour enregistrer un rendez-vous
void enregistrer_rendezvous() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                  ENREGISTREMENT D'UN RENDEZ-VOUS              ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_medecins == 0) {
        afficher_erreur("Aucun médecin disponible.");
        faire_pause();
        return;
    }
    
    if (nb_patients == 0) {
        afficher_erreur("Aucun patient enregistré.");
        faire_pause();
        return;
    }
    
    if (nb_rendezvous >= MAX_RENDEZVOUS) {
        afficher_erreur("Nombre maximum de rendez-vous atteint.");
        faire_pause();
        return;
    }
    
    RendezVous nouveau_rdv;
    nouveau_rdv.id = nb_rendezvous + 1;
    
    // Génération automatique du numéro de rendez-vous
    strcpy(nouveau_rdv.numero, generer_numero_rdv());
    
    // Choix du médecin
    printf("Médecins disponibles:\n");
    for (int i = 0; i < nb_medecins; i++) {
        if (medecins[i].etat == 1) {
            printf("%d. %s (Spécialité: %s, Cabinet: %d)\n", 
                   i + 1, medecins[i].matricule, medecins[i].specialite, medecins[i].numero_cabinet);
        }
    }
    
    printf("\nChoix du médecin (1-%d): ", nb_medecins);
    int choix_medecin = lire_entier();
    
    if (choix_medecin < 1 || choix_medecin > nb_medecins) {
        afficher_erreur("Choix de médecin invalide.");
        faire_pause();
        return;
    }
    
    if (medecins[choix_medecin - 1].etat == 0) {
        afficher_erreur("Ce médecin n'est pas actif.");
        faire_pause();
        return;
    }
    
    nouveau_rdv.id_medecin = medecins[choix_medecin - 1].id;
    
    // Saisie de la date
    printf("Date du rendez-vous (JJ/MM/AAAA): ");
    lire_chaine(nouveau_rdv.date, sizeof(nouveau_rdv.date));
    
    // Vérifier la disponibilité du médecin
    if (!verifier_disponibilite_medecin(nouveau_rdv.id_medecin, nouveau_rdv.date)) {
        afficher_erreur("Ce médecin n'est pas disponible à cette date.");
        faire_pause();
        return;
    }
    
    // Saisie du motif
    printf("Motif du rendez-vous: ");
    lire_chaine(nouveau_rdv.motif, sizeof(nouveau_rdv.motif));
    
    // Informations sur l'utilisateur qui enregistre
    nouveau_rdv.id_user = utilisateur_courant->id;
    
    // Statut actif
    nouveau_rdv.statut = 1;
    
    // Choix du patient
    printf("\nPatients disponibles:\n");
    for (int i = 0; i < nb_patients; i++) {
        printf("%d. %s %s\n", i + 1, patients[i].prenom, patients[i].nom);
    }
    
    printf("\nChoix du patient (1-%d): ", nb_patients);
    int choix_patient = lire_entier();
    
    if (choix_patient < 1 || choix_patient > nb_patients) {
        afficher_erreur("Choix de patient invalide.");
        faire_pause();
        return;
    }
    
    strcpy(nouveau_rdv.nom_patient, patients[choix_patient - 1].nom);
    strcpy(nouveau_rdv.prenom_patient, patients[choix_patient - 1].prenom);
    
    // Ajouter le rendez-vous
    rendezvous[nb_rendezvous++] = nouveau_rdv;
    
    // Créer le fichier de rendez-vous
    char nom_fichier[100];
    sprintf(nom_fichier, "RENDEZVOUS/RDV_%s_%02d_%s.txt", 
            nouveau_rdv.numero, nouveau_rdv.id, utilisateur_courant->login);
    
    FILE* fichier = fopen(nom_fichier, "w");
    if (fichier != NULL) {
        fprintf(fichier, "RENDEZ-VOUS\n");
        fprintf(fichier, "===========\n\n");
        fprintf(fichier, "Numéro: %s\n", nouveau_rdv.numero);
        fprintf(fichier, "Médecin: %s (ID: %d)\n", medecins[choix_medecin - 1].specialite, nouveau_rdv.id_medecin);
        fprintf(fichier, "Date: %s\n", nouveau_rdv.date);
        fprintf(fichier, "Patient: %s %s\n", nouveau_rdv.prenom_patient, nouveau_rdv.nom_patient);
        fprintf(fichier, "Motif: %s\n", nouveau_rdv.motif);
        fprintf(fichier, "Enregistré par: %s %s\n", utilisateur_courant->prenom, utilisateur_courant->nom);
        fprintf(fichier, "Statut: %s\n", nouveau_rdv.statut ? "Actif" : "Inactif");
        fclose(fichier);
    }
    
    afficher_succes("Rendez-vous enregistré avec succès !");
    printf("Numéro de rendez-vous: %s\n", nouveau_rdv.numero);
    printf("Fichier créé: %s\n", nom_fichier);
    
    faire_pause();
}

// Fonction pour libérer un médecin
void liberer_medecin() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    LIBÉRATION D'UN MÉDECIN                   ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_rendezvous == 0) {
        afficher_info("Aucun rendez-vous à traiter.");
        faire_pause();
        return;
    }
    
    printf("Rendez-vous actifs:\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ %-5s │ %-20s │ %-8s │ %-12s │ %-20s ║\n", "ID", "Numéro", "Médecin", "Date", "Patient");
    printf("╟══════════════════════════════════════════════════════════════════════════════════════════════════════╢\n");
    
    for (int i = 0; i < nb_rendezvous; i++) {
        if (rendezvous[i].statut == 1) {
            printf("║ %-5d │ %-20s │ %-8d │ %-12s │ %-20s ║\n",
                   rendezvous[i].id,
                   rendezvous[i].numero,
                   rendezvous[i].id_medecin,
                   rendezvous[i].date,
                   rendezvous[i].nom_patient);
        }
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    
    printf("\nEntrez l'ID du rendez-vous terminé: ");
    int id = lire_entier();
    
    if (id <= 0 || id > nb_rendezvous) {
        afficher_erreur("ID de rendez-vous invalide.");
        faire_pause();
        return;
    }
    
    RendezVous* rdv = &rendezvous[id - 1];
    
    if (rdv->statut == 0) {
        afficher_info("Ce rendez-vous est déjà terminé.");
        faire_pause();
        return;
    }
    
    printf("Rendez-vous sélectionné: %s pour %s %s\n", 
           rdv->numero, rdv->prenom_patient, rdv->nom_patient);
    
    if (confirmer_action("Voulez-vous vraiment marquer ce rendez-vous comme terminé ?")) {
        rdv->statut = 0;
        afficher_succes("Médecin libéré avec succès !");
    }
    
    faire_pause();
}

// Fonction pour annuler un rendez-vous
void annuler_rendezvous() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                  ANNULATION D'UN RENDEZ-VOUS                 ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (nb_rendezvous == 0) {
        afficher_info("Aucun rendez-vous à annuler.");
        faire_pause();
        return;
    }
    
    lister_tous_rendezvous();
    
    printf("\nEntrez l'ID du rendez-vous à annuler: ");
    int id = lire_entier();
    
    if (id <= 0 || id > nb_rendezvous) {
        afficher_erreur("ID de rendez-vous invalide.");
        faire_pause();
        return;
    }
    
    RendezVous* rdv = &rendezvous[id - 1];
    
    if (rdv->statut == 0) {
        afficher_info("Ce rendez-vous est déjà annulé.");
        faire_pause();
        return;
    }
    
    printf("Rendez-vous sélectionné: %s pour %s %s\n", 
           rdv->numero, rdv->prenom_patient, rdv->nom_patient);
    
    if (confirmer_action("Voulez-vous vraiment annuler ce rendez-vous ?")) {
        rdv->statut = 0;
        afficher_succes("Rendez-vous annulé avec succès !");
    }
    
    faire_pause();
}