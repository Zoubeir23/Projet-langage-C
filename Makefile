# Makefile pour le projet de gestion de clinique
# Auteur: Sandra
# Année: 2024-2025

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c99 -g

# Nom de l'exécutable
TARGET = clinique

# Fichiers source
SOURCES = main.c utils.c auth.c menus.c gestion_medecins.c gestion_patients_rdv.c gestion_donnees.c

# Fichiers objet
OBJECTS = $(SOURCES:.c=.o)

# Règle par défaut
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "✅ Compilation réussie !"
	@echo "🎯 Exécutable créé: $(TARGET)"

# Compilation des fichiers objet
%.o: %.c clinique.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "🧹 Nettoyage effectué"

# Installation
install: $(TARGET)
	@echo "📦 Installation..."
	@if [ -w /usr/local/bin ]; then \
		sudo cp $(TARGET) /usr/local/bin/; \
		echo "✅ Installation dans /usr/local/bin/"; \
	else \
		echo "⚠️  Impossible d'installer dans /usr/local/bin/"; \
		echo "💡 Vous pouvez copier manuellement l'exécutable"; \
	fi

# Désinstallation
uninstall:
	@echo "🗑️  Désinstallation..."
	@if [ -f /usr/local/bin/$(TARGET) ]; then \
		sudo rm -f /usr/local/bin/$(TARGET); \
		echo "✅ Désinstallation réussie"; \
	else \
		echo "ℹ️  $(TARGET) n'est pas installé"; \
	fi

# Exécution
run: $(TARGET)
	@echo "🚀 Lancement de l'application..."
	./$(TARGET)

# Démonstration
demo: $(TARGET)
	@echo "🎭 Lancement avec données de démonstration..."
	@echo "💡 Utilisez le menu gestionnaire pour créer des données de démonstration"

# Aide
help:
	@echo "📋 Aide du Makefile:"
	@echo "  all        - Compile le projet (défaut)"
	@echo "  clean      - Nettoie les fichiers de compilation"
	@echo "  install    - Installe l'application dans /usr/local/bin/"
	@echo "  uninstall  - Désinstalle l'application"
	@echo "  run        - Compile et lance l'application"
	@echo "  demo       - Affiche les informations de démonstration"
	@echo "  help       - Affiche cette aide"

# Règles spéciales
.PHONY: all clean install uninstall run demo help

# Informations sur le projet
info:
	@echo "🏥 PROJET DE GESTION D'UNE CLINIQUE"
	@echo "=================================="
	@echo "Auteur: Sandra"
	@echo "Année: 2024-2025"
	@echo "Clinic: Saa Tank Sama Tank"
	@echo ""
	@echo "📁 Structure du projet:"
	@echo "  - main.c: Programme principal"
	@echo "  - utils.c: Fonctions utilitaires"
	@echo "  - auth.c: Authentification et gestion des utilisateurs"
	@echo "  - menus.c: Interface utilisateur et menus"
	@echo "  - gestion_medecins.c: Gestion des médecins et spécialités"
	@echo "  - gestion_patients_rdv.c: Gestion des patients et rendez-vous"
	@echo "  - gestion_donnees.c: Sauvegarde et chargement des données"
	@echo "  - clinique.h: Fichier d'en-tête principal"
	@echo ""
	@echo "🔑 Connexion par défaut:"
	@echo "  Login: ADMIN"
	@echo "  Mot de passe: passerstst"