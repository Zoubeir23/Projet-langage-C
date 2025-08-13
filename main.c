#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

// Constantes
#define MAX_SPECIALITES 3
#define MAX_MEDECINS 40
#define MAX_USERS 100
#define MAX_PATIENTS 1000
#define MAX_RENDEZVOUS 1000
#define MAX_STRING 100
#define LOGIN_LENGTH 5
#define PASSWORD_LENGTH 20
#define DEFAULT_PASSWORD "passerstst"

// Structures de données
typedef struct {
    int id;
    char code[10];
    char libelle[50];
    char description[200];
} Specialite;

typedef struct {
    int id;
    char matricule[20];
    int numero_cabinet;
    int etat; // 1 = actif, 0 = inactif
    char specialite[50];
} Medecin;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char telephone[20];
    char email[100];
    char login[LOGIN_LENGTH + 1];
    char mot_de_passe[PASSWORD_LENGTH + 1];
    int type; // 1 = gestionnaire, 2 = secretaire
    int premier_connexion; // 1 = oui, 0 = non
} Utilisateur;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char adresse[200];
    char telephone[20];
} Patient;

typedef struct {
    int id;
    char numero[20]; // Format: AAAAMMDDHHmmSS
    int id_medecin;
    char date[20];
    char motif[200];
    int id_user;
    int statut; // 1 = actif, 0 = inactif
    char nom_patient[50];
    char prenom_patient[50];
} RendezVous;

// Variables globales
Specialite specialites[MAX_SPECIALITES];
Medecin medecins[MAX_MEDECINS];
Utilisateur users[MAX_USERS];
Patient patients[MAX_PATIENTS];
RendezVous rendezvous[MAX_RENDEZVOUS];

int nb_specialites = 0;
int nb_medecins = 0;
int nb_users = 0;
int nb_patients = 0;
int nb_rendezvous = 0;
Utilisateur* utilisateur_courant = NULL;

// Prototypes des fonctions
void initialiser_systeme();
void afficher_menu_principal();
void afficher_menu_gestionnaire();
void afficher_menu_secretaire();
void connexion();
void creer_utilisateur();
void gerer_medecins();
void gerer_specialites();
void gerer_patients();
void gerer_rendezvous();
void lister_medecins_disponibles();
void lister_rendezvous_en_cours();
void lister_patients_avec_rdv();
void filtrer_rendezvous_par_statut();
void enregistrer_rendezvous();
void liberer_medecin();
void changer_mot_de_passe();
void sauvegarder_donnees();
void charger_donnees();
char* generer_email(const char* nom, int annee);
char* generer_matricule(const char* specialite, int id);
char* generer_numero_rdv();
void crypter_mot_de_passe(const char* mot_de_passe, char* mot_crypte);
void decrypter_mot_de_passe(const char* mot_crypte, char* mot_de_passe);
int verifier_disponibilite_medecin(int id_medecin, const char* date);
void afficher_banniere();

int main() {
    afficher_banniere();
    initialiser_systeme();
    charger_donnees();
    
    while (1) {
        if (utilisateur_courant == NULL) {
            connexion();
        } else {
            if (utilisateur_courant->premier_connexion) {
                changer_mot_de_passe();
            }
            
            if (utilisateur_courant->type == 1) {
                afficher_menu_gestionnaire();
            } else {
                afficher_menu_secretaire();
            }
        }
    }
    
    return 0;
}