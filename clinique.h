#ifndef CLINIQUE_H
#define CLINIQUE_H

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
extern Specialite specialites[];
extern Medecin medecins[];
extern Utilisateur users[];
extern Patient patients[];
extern RendezVous rendezvous[];
extern int nb_specialites, nb_medecins, nb_users, nb_patients, nb_rendezvous;
extern Utilisateur* utilisateur_courant;

// Prototypes des fonctions utilitaires
void afficher_banniere();
char* generer_email(const char* nom, int annee);
char* generer_matricule(const char* specialite, int id);
char* generer_numero_rdv();
void crypter_mot_de_passe(const char* mot_de_passe, char* mot_crypte);
void decrypter_mot_de_passe(const char* mot_crypte, char* mot_de_passe);
int verifier_disponibilite_medecin(int id_medecin, const char* date);
int obtenir_annee_actuelle();
int valider_login(const char* login);
void nettoyer_ecran();
void faire_pause();
void afficher_erreur(const char* message);
void afficher_succes(const char* message);
void afficher_info(const char* message);
void lire_chaine(char* buffer, int taille);
int lire_entier();
int confirmer_action(const char* message);

// Prototypes des fonctions principales
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

// Prototypes des fonctions de gestion des médecins
void creer_medecin();
void modifier_medecin();
void archiver_medecin();
void lister_tous_medecins();
void creer_specialite();
void modifier_specialite();
void lister_toutes_specialites();

// Prototypes des fonctions de gestion des patients
void creer_patient();
void modifier_patient();
void lister_tous_patients();

// Prototypes des fonctions de gestion des rendez-vous
void lister_tous_rendezvous();
void annuler_rendezvous();

// Prototypes des fonctions utilitaires d'affichage
void afficher_tableau_medecins();
void afficher_tableau_specialites();
void afficher_tableau_patients();
void afficher_tableau_rendezvous();

// Prototypes des fonctions de gestion des données
int sauvegarder_specialites();
int sauvegarder_medecins();
int sauvegarder_users();
int sauvegarder_patients();
int sauvegarder_rendezvous();
int charger_specialites();
int charger_medecins();
int charger_users();
int charger_patients();
int charger_rendezvous();
void creer_donnees_demo();

#endif // CLINIQUE_H