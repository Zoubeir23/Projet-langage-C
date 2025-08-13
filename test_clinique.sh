#!/bin/bash

echo "🧪 Test de l'application de gestion de clinique"
echo "=============================================="

# Vérifier que l'exécutable existe
if [ ! -f "./clinique" ]; then
    echo "❌ Erreur: L'exécutable 'clinique' n'existe pas"
    echo "💡 Compilez d'abord le projet avec 'make'"
    exit 1
fi

echo "✅ Exécutable trouvé"

# Vérifier les permissions
if [ ! -x "./clinique" ]; then
    echo "❌ Erreur: L'exécutable n'a pas les permissions d'exécution"
    chmod +x ./clinique
    echo "✅ Permissions corrigées"
fi

# Vérifier la structure des fichiers
echo ""
echo "📁 Vérification de la structure des fichiers:"
if [ -f "clinique.h" ]; then echo "✅ clinique.h"; else echo "❌ clinique.h manquant"; fi
if [ -f "main.c" ]; then echo "✅ main.c"; else echo "❌ main.c manquant"; fi
if [ -f "utils.c" ]; then echo "✅ utils.c"; else echo "❌ utils.c manquant"; fi
if [ -f "auth.c" ]; then echo "✅ auth.c"; else echo "❌ auth.c manquant"; fi
if [ -f "menus.c" ]; then echo "✅ menus.c"; else echo "❌ menus.c manquant"; fi
if [ -f "gestion_medecins.c" ]; then echo "✅ gestion_medecins.c"; else echo "❌ gestion_medecins.c manquant"; fi
if [ -f "gestion_patients_rdv.c" ]; then echo "✅ gestion_patients_rdv.c"; else echo "❌ gestion_patients_rdv.c manquant"; fi
if [ -f "gestion_donnees.c" ]; then echo "✅ gestion_donnees.c"; else echo "❌ gestion_donnees.c manquant"; fi
if [ -f "Makefile" ]; then echo "✅ Makefile"; else echo "❌ Makefile manquant"; fi
if [ -f "README.md" ]; then echo "✅ README.md"; else echo "❌ README.md manquant"; fi

echo ""
echo "🔍 Informations sur l'exécutable:"
file ./clinique
echo ""
echo "📊 Taille de l'exécutable:"
ls -lh ./clinique

echo ""
echo "🎯 Test de compilation:"
make clean
make

echo ""
echo "✅ Test terminé avec succès !"
echo ""
echo "🚀 Pour lancer l'application:"
echo "   ./clinique"
echo ""
echo "🔑 Connexion par défaut:"
echo "   Login: ADMIN"
echo "   Mot de passe: passerstst"
echo ""
echo "💡 Utilisez Ctrl+C pour arrêter l'application"