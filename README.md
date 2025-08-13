# 🏥 PROJET DE GESTION D'UNE CLINIQUE

## 📋 Description

Application de gestion complète pour la clinique **"Saa Tank Sama Tank"** développée en langage C. Ce système permet la gestion des médecins, spécialités, patients, rendez-vous et utilisateurs selon les spécifications du projet académique.

## 👨‍💻 Auteur

- **Nom:** M GAYE Abdoulaye
- **Année:** 2024 - 2025
- **Cours:** L1GL NR

## 🎯 Fonctionnalités

### 👥 Gestion des Utilisateurs
- **2 types d'utilisateurs:**
  - **Gestionnaire de la clinique:** Peut créer de nouveaux utilisateurs
  - **Secrétaire:** Accès limité aux fonctionnalités de base
- **Système d'authentification sécurisé**
- **Génération automatique des emails** (format: `ge2025@satanksamatank.sn`)
- **Login fixe de 5 caractères majuscules** (ex: `ADMIN`)
- **Mot de passe par défaut:** `passerstst`
- **Changement obligatoire du mot de passe** lors de la première connexion

### 🩺 Gestion des Médecins
- **Maximum 40 médecins**
- **Matricule automatique** (format: `SPECIALITE000ID`)
- **Numéro de cabinet**
- **Statut actif/inactif**
- **Spécialité obligatoire** (doit exister dans la liste des spécialités)

### 🏷️ Gestion des Spécialités
- **Maximum 3 spécialités**
- **Code, libellé et description**
- **Contrainte:** Un médecin ne peut avoir qu'une spécialité listée

### 👤 Gestion des Patients
- **Informations complètes:** nom, prénom, adresse, téléphone
- **ID auto-généré**

### 📅 Gestion des Rendez-vous
- **Numéro unique** au format `AAAAMMDDHHmmSS`
- **Un rendez-vous = Un médecin**
- **Fichiers texte** dans le dossier `RENDEZVOUS/`
- **Nommage des fichiers:** `RDV_AAAAMMDDHHMMSS_II_LL.txt`
  - `AAAA`: Année
  - `MM`: Mois
  - `DD`: Jour
  - `HH`: Heure
  - `mm`: Minute
  - `SS`: Seconde
  - `II`: ID du rendez-vous
  - `LL`: Login de l'utilisateur

## 🔐 Sécurité

- **Cryptage des mots de passe** avec algorithme personnalisé
- **Validation des logins** (exactement 5 caractères alphabétiques majuscules)
- **Gestion des permissions** selon le type d'utilisateur

## 📁 Structure des Fichiers

```
clinique/
├── main.c                          # Programme principal
├── clinique.h                      # Fichier d'en-tête principal
├── utils.c                         # Fonctions utilitaires
├── auth.c                          # Authentification et gestion utilisateurs
├── menus.c                         # Interface utilisateur et menus
├── gestion_medecins.c              # Gestion médecins et spécialités
├── gestion_patients_rdv.c          # Gestion patients et rendez-vous
├── gestion_donnees.c               # Sauvegarde et chargement
├── Makefile                        # Compilation du projet
├── README.md                       # Documentation
└── RENDEZVOUS/                     # Dossier des fichiers de rendez-vous
```

## 🗄️ Fichiers de Données

- **`SPECIALITES`** - Fichier binaire des spécialités
- **`MEDECINS`** - Fichier binaire des médecins
- **`USERS`** - Fichier binaire des utilisateurs
- **`PATIENTS`** - Fichier binaire des patients
- **`RENDEZVOUS_DATA`** - Fichier binaire des rendez-vous
- **`RENDEZVOUS/`** - Dossier contenant les fichiers texte des rendez-vous

## 🚀 Installation et Compilation

### Prérequis
- **GCC** (GNU Compiler Collection)
- **Make** (GNU Make)
- **Système Linux/Unix**

### Compilation
```bash
# Compiler le projet
make

# Ou explicitement
make all
```

### Exécution
```bash
# Lancer l'application
make run

# Ou directement
./clinique
```

### Installation système
```bash
# Installer dans /usr/local/bin/
sudo make install

# Désinstaller
sudo make uninstall
```

### Nettoyage
```bash
# Nettoyer les fichiers de compilation
make clean
```

## 🔑 Première Utilisation

1. **Lancer l'application:** `./clinique`
2. **Se connecter avec:**
   - **Login:** `ADMIN`
   - **Mot de passe:** `passerstst`
3. **Changer le mot de passe** lors de la première connexion
4. **Créer des spécialités** (maximum 3)
5. **Créer des médecins** (maximum 40)
6. **Créer des patients**
7. **Gérer les rendez-vous**

## 📊 Données de Démonstration

L'application peut créer automatiquement des données de démonstration :
- 3 spécialités (Cardiologie, Pédiatrie, Dermatologie)
- 3 médecins (un par spécialité)
- 3 patients
- 2 rendez-vous

## 🎮 Utilisation

### Menu Gestionnaire
- Créer/modifier des utilisateurs
- Gérer les médecins et spécialités
- Gérer les patients
- Accès complet à toutes les fonctionnalités

### Menu Secrétaire
- Vérifier la disponibilité des médecins
- Lister les patients avec rendez-vous
- Enregistrer des rendez-vous
- Libérer des médecins (marquer les RDV comme terminés)

## ⚠️ Contraintes et Limitations

- **Maximum 3 spécialités** pour la clinique
- **Maximum 40 médecins**
- **Maximum 100 utilisateurs**
- **Maximum 1000 patients**
- **Maximum 1000 rendez-vous**
- **Un rendez-vous ne concerne qu'un seul médecin**
- **Le gestionnaire peut faire tout ce que le secrétaire peut faire**

## 🐛 Dépannage

### Problèmes de compilation
```bash
# Vérifier la version de GCC
gcc --version

# Nettoyer et recompiler
make clean
make
```

### Problèmes d'exécution
- Vérifier les permissions d'écriture dans le répertoire
- S'assurer que le dossier `RENDEZVOUS/` peut être créé
- Vérifier l'espace disque disponible

## 📝 Notes Techniques

- **Langage:** C99
- **Compilateur:** GCC avec options `-Wall -Wextra -std=c99 -g`
- **Système de fichiers:** Binaire pour les données, texte pour les rendez-vous
- **Interface:** Terminal avec menus textuels
- **Gestion mémoire:** Tableaux statiques (pas d'allocation dynamique)

## 🤝 Contribution

Ce projet est développé dans le cadre d'un cours académique. Pour toute question ou suggestion, veuillez contacter l'auteur.

## 📄 Licence

Projet académique - Tous droits réservés à l'auteur.

---

**🏥 Saa Tank Sama Tank - Gestion Clinique 2024-2025**