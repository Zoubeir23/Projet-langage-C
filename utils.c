#include "clinique.h"

// Fonction pour afficher la bannière
void afficher_banniere() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    GESTION CLINIQUE                         ║\n");
    printf("║                  SAA TANK SAMA TANK                        ║\n");
    printf("║                    2024 - 2025                              ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("\n");
}

// Fonction pour générer un email automatiquement
char* generer_email(const char* nom, int annee) {
    static char email[100];
    if (strlen(nom) > 0) {
        char premier = tolower(nom[0]);
        char dernier = tolower(nom[strlen(nom) - 1]);
        sprintf(email, "%c%c%d@satanksamatank.sn", premier, dernier, annee);
    } else {
        strcpy(email, "user@satanksamatank.sn");
    }
    return email;
}

// Fonction pour générer un matricule de médecin
char* generer_matricule(const char* specialite, int id) {
    static char matricule[20];
    sprintf(matricule, "%s000%d", specialite, id);
    return matricule;
}

// Fonction pour générer un numéro de rendez-vous
char* generer_numero_rdv() {
    static char numero[20];
    time_t maintenant = time(NULL);
    struct tm *tm_info = localtime(&maintenant);
    
    sprintf(numero, "%04d%02d%02d%02d%02d%02d", 
            tm_info->tm_year + 1900,
            tm_info->tm_mon + 1,
            tm_info->tm_mday,
            tm_info->tm_hour,
            tm_info->tm_min,
            tm_info->tm_sec);
    
    return numero;
}

// Fonction de cryptage simple des mots de passe
void crypter_mot_de_passe(const char* mot_de_passe, char* mot_crypte) {
    int len = strlen(mot_de_passe);
    for (int i = 0; i < len; i++) {
        mot_crypte[i] = mot_de_passe[i] + 13; // Cryptage par décalage
    }
    mot_crypte[len] = '\0';
}

// Fonction de décryptage des mots de passe
void decrypter_mot_de_passe(const char* mot_crypte, char* mot_de_passe) {
    int len = strlen(mot_crypte);
    for (int i = 0; i < len; i++) {
        mot_de_passe[i] = mot_crypte[i] - 13; // Décryptage par décalage
    }
    mot_de_passe[len] = '\0';
}

// Fonction pour vérifier la disponibilité d'un médecin
int verifier_disponibilite_medecin(int id_medecin, const char* date) {
    for (int i = 0; i < nb_rendezvous; i++) {
        if (rendezvous[i].id_medecin == id_medecin && 
            rendezvous[i].statut == 1 && 
            strcmp(rendezvous[i].date, date) == 0) {
            return 0; // Non disponible
        }
    }
    return 1; // Disponible
}

// Fonction pour obtenir l'année actuelle
int obtenir_annee_actuelle() {
    time_t maintenant = time(NULL);
    struct tm *tm_info = localtime(&maintenant);
    return tm_info->tm_year + 1900;
}

// Fonction pour valider un login (exactement 5 caractères alphabétiques majuscules)
int valider_login(const char* login) {
    if (strlen(login) != LOGIN_LENGTH) {
        return 0;
    }
    
    for (int i = 0; i < LOGIN_LENGTH; i++) {
        if (!isalpha(login[i]) || !isupper(login[i])) {
            return 0;
        }
    }
    return 1;
}

// Fonction pour nettoyer l'écran
void nettoyer_ecran() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fonction pour faire une pause
void faire_pause() {
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar();
    getchar(); // Pour absorber le \n restant
}

// Fonction pour afficher un message d'erreur
void afficher_erreur(const char* message) {
    printf("\n❌ ERREUR: %s\n", message);
}

// Fonction pour afficher un message de succès
void afficher_succes(const char* message) {
    printf("\n✅ %s\n", message);
}

// Fonction pour afficher un message d'information
void afficher_info(const char* message) {
    printf("\nℹ️  %s\n", message);
}

// Fonction pour lire une chaîne de caractères avec gestion des espaces
void lire_chaine(char* buffer, int taille) {
    fgets(buffer, taille, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Supprimer le \n
}

// Fonction pour lire un entier avec validation
int lire_entier() {
    int valeur;
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    if (sscanf(buffer, "%d", &valeur) != 1) {
        return -1; // Valeur invalide
    }
    return valeur;
}

// Fonction pour confirmer une action
int confirmer_action(const char* message) {
    char reponse;
    printf("%s (o/n): ", message);
    scanf(" %c", &reponse);
    getchar(); // Absorber le \n
    return (reponse == 'o' || reponse == 'O');
}