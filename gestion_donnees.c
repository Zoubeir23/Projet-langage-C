#include "clinique.h"

// Fonction pour sauvegarder toutes les données
void sauvegarder_donnees() {
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    SAUVEGARDE DES DONNÉES                     ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    int succes = 1;
    
    // Sauvegarder les spécialités
    if (sauvegarder_specialites()) {
        printf("✅ Spécialités sauvegardées avec succès\n");
    } else {
        printf("❌ Erreur lors de la sauvegarde des spécialités\n");
        succes = 0;
    }
    
    // Sauvegarder les médecins
    if (sauvegarder_medecins()) {
        printf("✅ Médecins sauvegardés avec succès\n");
    } else {
        printf("❌ Erreur lors de la sauvegarde des médecins\n");
        succes = 0;
    }
    
    // Sauvegarder les utilisateurs
    if (sauvegarder_users()) {
        printf("✅ Utilisateurs sauvegardés avec succès\n");
    } else {
        printf("❌ Erreur lors de la sauvegarde des utilisateurs\n");
        succes = 0;
    }
    
    // Sauvegarder les patients
    if (sauvegarder_patients()) {
        printf("✅ Patients sauvegardés avec succès\n");
    } else {
        printf("❌ Erreur lors de la sauvegarde des patients\n");
        succes = 0;
    }
    
    // Sauvegarder les rendez-vous
    if (sauvegarder_rendezvous()) {
        printf("✅ Rendez-vous sauvegardés avec succès\n");
    } else {
        printf("❌ Erreur lors de la sauvegarde des rendez-vous\n");
        succes = 0;
    }
    
    if (succes) {
        afficher_succes("Toutes les données ont été sauvegardées avec succès !");
    } else {
        afficher_erreur("Certaines données n'ont pas pu être sauvegardées.");
    }
    
    faire_pause();
}

// Fonction pour charger toutes les données
void charger_donnees() {
    printf("Chargement des données...\n");
    
    // Charger les spécialités
    if (charger_specialites()) {
        printf("✅ Spécialités chargées (%d)\n", nb_specialites);
    } else {
        printf("ℹ️  Aucune spécialité trouvée, création d'un fichier vide\n");
        nb_specialites = 0;
    }
    
    // Charger les médecins
    if (charger_medecins()) {
        printf("✅ Médecins chargés (%d)\n", nb_medecins);
    } else {
        printf("ℹ️  Aucun médecin trouvé, création d'un fichier vide\n");
        nb_medecins = 0;
    }
    
    // Charger les utilisateurs
    if (charger_users()) {
        printf("✅ Utilisateurs chargés (%d)\n", nb_users);
    } else {
        printf("ℹ️  Aucun utilisateur trouvé, création d'un fichier vide\n");
        nb_users = 0;
    }
    
    // Charger les patients
    if (charger_patients()) {
        printf("✅ Patients chargés (%d)\n", nb_patients);
    } else {
        printf("ℹ️  Aucun patient trouvé, création d'un fichier vide\n");
        nb_patients = 0;
    }
    
    // Charger les rendez-vous
    if (charger_rendezvous()) {
        printf("✅ Rendez-vous chargés (%d)\n", nb_rendezvous);
    } else {
        printf("ℹ️  Aucun rendez-vous trouvé, création d'un fichier vide\n");
        nb_rendezvous = 0;
    }
    
    printf("\n");
}

// Fonction pour sauvegarder les spécialités
int sauvegarder_specialites() {
    FILE* fichier = fopen("SPECIALITES", "wb");
    if (fichier == NULL) {
        return 0;
    }
    
    fwrite(&nb_specialites, sizeof(int), 1, fichier);
    if (nb_specialites > 0) {
        fwrite(specialites, sizeof(Specialite), nb_specialites, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour charger les spécialités
int charger_specialites() {
    FILE* fichier = fopen("SPECIALITES", "rb");
    if (fichier == NULL) {
        return 0;
    }
    
    fread(&nb_specialites, sizeof(int), 1, fichier);
    if (nb_specialites > 0) {
        fread(specialites, sizeof(Specialite), nb_specialites, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour sauvegarder les médecins
int sauvegarder_medecins() {
    FILE* fichier = fopen("MEDECINS", "wb");
    if (fichier == NULL) {
        return 0;
    }
    
    fwrite(&nb_medecins, sizeof(int), 1, fichier);
    if (nb_medecins > 0) {
        fwrite(medecins, sizeof(Medecin), nb_medecins, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour charger les médecins
int charger_medecins() {
    FILE* fichier = fopen("MEDECINS", "rb");
    if (fichier == NULL) {
        return 0;
    }
    
    fread(&nb_medecins, sizeof(int), 1, fichier);
    if (nb_medecins > 0) {
        fread(medecins, sizeof(Medecin), nb_medecins, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour sauvegarder les utilisateurs
int sauvegarder_users() {
    FILE* fichier = fopen("USERS", "wb");
    if (fichier == NULL) {
        return 0;
    }
    
    fwrite(&nb_users, sizeof(int), 1, fichier);
    if (nb_users > 0) {
        fwrite(users, sizeof(Utilisateur), nb_users, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour charger les utilisateurs
int charger_users() {
    FILE* fichier = fopen("USERS", "rb");
    if (fichier == NULL) {
        return 0;
    }
    
    fread(&nb_users, sizeof(int), 1, fichier);
    if (nb_users > 0) {
        fread(users, sizeof(Utilisateur), nb_users, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour sauvegarder les patients
int sauvegarder_patients() {
    FILE* fichier = fopen("PATIENTS", "wb");
    if (fichier == NULL) {
        return 0;
    }
    
    fwrite(&nb_patients, sizeof(int), 1, fichier);
    if (nb_patients > 0) {
        fwrite(patients, sizeof(Patient), nb_patients, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour charger les patients
int charger_patients() {
    FILE* fichier = fopen("PATIENTS", "rb");
    if (fichier == NULL) {
        return 0;
    }
    
    fread(&nb_patients, sizeof(int), 1, fichier);
    if (nb_patients > 0) {
        fread(patients, sizeof(Patient), nb_patients, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour sauvegarder les rendez-vous
int sauvegarder_rendezvous() {
    FILE* fichier = fopen("RENDEZVOUS_DATA", "wb");
    if (fichier == NULL) {
        return 0;
    }
    
    fwrite(&nb_rendezvous, sizeof(int), 1, fichier);
    if (nb_rendezvous > 0) {
        fwrite(rendezvous, sizeof(RendezVous), nb_rendezvous, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour charger les rendez-vous
int charger_rendezvous() {
    FILE* fichier = fopen("RENDEZVOUS_DATA", "rb");
    if (fichier == NULL) {
        return 0;
    }
    
    fread(&nb_rendezvous, sizeof(int), 1, fichier);
    if (nb_rendezvous > 0) {
        fread(rendezvous, sizeof(RendezVous), nb_rendezvous, fichier);
    }
    
    fclose(fichier);
    return 1;
}

// Fonction pour créer des données de démonstration
void creer_donnees_demo() {
    if (utilisateur_courant == NULL || utilisateur_courant->type != 1) {
        afficher_erreur("Accès refusé. Seuls les gestionnaires peuvent créer des données de démonstration.");
        return;
    }
    
    nettoyer_ecran();
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                CRÉATION DE DONNÉES DE DÉMONSTRATION           ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    
    if (confirmer_action("Voulez-vous créer des données de démonstration ? Cela remplacera toutes les données existantes.")) {
        // Réinitialiser les compteurs
        nb_specialites = 0;
        nb_medecins = 0;
        nb_patients = 0;
        nb_rendezvous = 0;
        
        // Créer des spécialités de démonstration
        Specialite spec1 = {1, "CARD", "Cardiologie", "Spécialité du cœur et des vaisseaux sanguins"};
        Specialite spec2 = {2, "PEDI", "Pédiatrie", "Spécialité des enfants et adolescents"};
        Specialite spec3 = {3, "DERM", "Dermatologie", "Spécialité de la peau et des muqueuses"};
        
        specialites[nb_specialites++] = spec1;
        specialites[nb_specialites++] = spec2;
        specialites[nb_specialites++] = spec3;
        
        // Créer des médecins de démonstration
        Medecin med1 = {1, "CARD0001", 101, 1, "Cardiologie"};
        Medecin med2 = {2, "PEDI0002", 102, 1, "Pédiatrie"};
        Medecin med3 = {3, "DERM0003", 103, 1, "Dermatologie"};
        
        medecins[nb_medecins++] = med1;
        medecins[nb_medecins++] = med2;
        medecins[nb_medecins++] = med3;
        
        // Créer des patients de démonstration
        Patient pat1 = {1, "DUPONT", "Jean", "123 Rue de la Paix, Paris", "0123456789"};
        Patient pat2 = {2, "MARTIN", "Marie", "456 Avenue des Champs, Lyon", "0987654321"};
        Patient pat3 = {3, "DURAND", "Pierre", "789 Boulevard Central, Marseille", "0555666777"};
        
        patients[nb_patients++] = pat1;
        patients[nb_patients++] = pat2;
        patients[nb_patients++] = pat3;
        
        // Créer des rendez-vous de démonstration
        RendezVous rdv1 = {1, "20250115140000", 1, "15/01/2025", "Consultation cardiaque", 1, 1, "DUPONT", "Jean"};
        RendezVous rdv2 = {2, "20250116150000", 2, "16/01/2025", "Vaccination enfant", 1, 1, "MARTIN", "Marie"};
        
        rendezvous[nb_rendezvous++] = rdv1;
        rendezvous[nb_rendezvous++] = rdv2;
        
        // Sauvegarder les données
        sauvegarder_donnees();
        
        afficher_succes("Données de démonstration créées avec succès !");
        printf("Spécialités: %d\n", nb_specialites);
        printf("Médecins: %d\n", nb_medecins);
        printf("Patients: %d\n", nb_patients);
        printf("Rendez-vous: %d\n", nb_rendezvous);
    }
    
    faire_pause();
}