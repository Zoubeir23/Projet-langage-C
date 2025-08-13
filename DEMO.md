# 🎭 Démonstration de l'Application de Gestion de Clinique

## 🚀 Lancement de l'Application

```bash
# Compiler le projet
make

# Lancer l'application
./clinique
```

## 🔑 Première Connexion

1. **Lancez l'application** avec `./clinique`
2. **Connectez-vous avec:**
   - **Login:** `ADMIN`
   - **Mot de passe:** `passerstst`
3. **Changez votre mot de passe** lors de la première connexion

## 📋 Scénario de Démonstration Complet

### Étape 1: Création des Spécialités
1. **Menu Gestionnaire** → **3. Gérer les spécialités**
2. **1. Créer une nouvelle spécialité**
   - Code: `CARD`
   - Libellé: `Cardiologie`
   - Description: `Spécialité du cœur et des vaisseaux sanguins`
3. **1. Créer une nouvelle spécialité**
   - Code: `PEDI`
   - Libellé: `Pédiatrie`
   - Description: `Spécialité des enfants et adolescents`
4. **1. Créer une nouvelle spécialité**
   - Code: `DERM`
   - Libellé: `Dermatologie`
   - Description: `Spécialité de la peau et des muqueuses`

### Étape 2: Création des Médecins
1. **Menu Gestionnaire** → **2. Gérer les médecins**
2. **1. Créer un nouveau médecin**
   - Numéro de cabinet: `101`
   - Spécialité: `1` (Cardiologie)
   - **Résultat:** Matricule généré `CARD0001`
3. **1. Créer un nouveau médecin**
   - Numéro de cabinet: `102`
   - Spécialité: `2` (Pédiatrie)
   - **Résultat:** Matricule généré `PEDI0002`
4. **1. Créer un nouveau médecin**
   - Numéro de cabinet: `103`
   - Spécialité: `3` (Dermatologie)
   - **Résultat:** Matricule généré `DERM0003`

### Étape 3: Création des Patients
1. **Menu Gestionnaire** → **4. Gérer les patients**
2. **1. Créer un nouveau patient**
   - Nom: `DUPONT`
   - Prénom: `Jean`
   - Adresse: `123 Rue de la Paix, Paris`
   - Téléphone: `0123456789`
3. **1. Créer un nouveau patient**
   - Nom: `MARTIN`
   - Prénom: `Marie`
   - Adresse: `456 Avenue des Champs, Lyon`
   - Téléphone: `0987654321`
4. **1. Créer un nouveau patient**
   - Nom: `DURAND`
   - Prénom: `Pierre`
   - Adresse: `789 Boulevard Central, Marseille`
   - Téléphone: `0555666777`

### Étape 4: Création d'un Utilisateur Secrétaire
1. **Menu Gestionnaire** → **1. Créer un nouvel utilisateur**
2. **Saisie des informations:**
   - Nom: `SECRET`
   - Prénom: `Alice`
   - Téléphone: `0123456789`
   - Login: `SEC01` (5 caractères majuscules)
   - Type: `2` (Secrétaire)
3. **Résultat:** Utilisateur créé avec mot de passe par défaut `passerstst`

### Étape 5: Enregistrement de Rendez-vous
1. **Menu Gestionnaire** → **10. Enregistrer un rendez-vous**
2. **Sélection du médecin:** `1` (Dr. CARD0001 - Cardiologie)
3. **Date:** `20/01/2025`
4. **Motif:** `Consultation cardiaque de routine`
5. **Patient:** `1` (Jean DUPONT)
6. **Résultat:** Rendez-vous créé avec numéro unique et fichier texte généré

### Étape 6: Test des Fonctionnalités Secrétaire
1. **Déconnexion** (choix `0`)
2. **Nouvelle connexion** avec `SEC01` / `passerstst`
3. **Changement du mot de passe** obligatoire
4. **Test des fonctionnalités:**
   - **1. Vérifier la disponibilité des médecins**
   - **2. Lister les patients avec rendez-vous**
   - **4. Enregistrer un nouveau rendez-vous**
   - **5. Libérer un médecin** (marquer un RDV comme terminé)

## 📊 Vérification des Données

### Lister les Spécialités
- **Menu Gestionnaire** → **3. Gérer les spécialités** → **3. Lister toutes les spécialités**

### Lister les Médecins
- **Menu Gestionnaire** → **2. Gérer les médecins** → **4. Lister tous les médecins**

### Lister les Patients
- **Menu Gestionnaire** → **4. Gérer les patients** → **3. Lister tous les patients**

### Lister les Rendez-vous
- **Menu Gestionnaire** → **5. Gérer les rendez-vous** → **1. Lister tous les rendez-vous**

## 🗂️ Fichiers Générés

Après la démonstration, vous devriez avoir :

### Fichiers Binaires
- `SPECIALITES` - 3 spécialités
- `MEDECINS` - 3 médecins
- `USERS` - 2 utilisateurs (ADMIN + SEC01)
- `PATIENTS` - 3 patients
- `RENDEZVOUS_DATA` - 1+ rendez-vous

### Dossier RENDEZVOUS/
- `RDV_20250120140000_01_ADMIN.txt` - Fichier du premier rendez-vous
- `RDV_20250120150000_02_SEC01.txt` - Fichier du second rendez-vous

## 🔍 Fonctionnalités Avancées

### Filtrage des Rendez-vous
- **Menu Gestionnaire** → **9. Filtrer les rendez-vous par statut**
- Choisir entre actifs et inactifs

### Modification des Données
- **Médecins:** Modifier cabinet ou spécialité
- **Patients:** Modifier informations personnelles
- **Spécialités:** Modifier libellé ou description

### Archivage
- **Médecins:** Marquer comme inactif (archivé)
- **Rendez-vous:** Annuler ou marquer comme terminé

## ⚠️ Points d'Attention

1. **Première connexion:** Changement obligatoire du mot de passe
2. **Ordre des opérations:** Créer les spécialités avant les médecins
3. **Contraintes:** Maximum 3 spécialités, 40 médecins
4. **Sauvegarde:** Utiliser **13. Sauvegarder les données** régulièrement
5. **Déconnexion:** Toujours utiliser l'option de déconnexion du menu

## 🎯 Objectifs de la Démonstration

✅ **Comprendre le workflow complet** de gestion d'une clinique  
✅ **Tester les deux types d'utilisateurs** (Gestionnaire et Secrétaire)  
✅ **Vérifier la génération automatique** des matricules et numéros de RDV  
✅ **Tester la persistance des données** avec les fichiers binaires  
✅ **Vérifier la création des fichiers de rendez-vous** au format spécifié  

## 🚀 Prochaines Étapes

Après la démonstration, vous pouvez :
- **Ajouter plus de données** (médecins, patients, rendez-vous)
- **Tester les cas limites** (nombre maximum d'éléments)
- **Explorer les fonctionnalités avancées** (filtrage, modification)
- **Créer des scénarios complexes** avec plusieurs rendez-vous simultanés

---

**🎭 Bonne démonstration ! L'application est prête à gérer votre clinique !**