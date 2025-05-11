
# ChenYI-Tech 




## Description générale
ChenYI-Tech est une application en langage C permettant de gérer un refuge animalier. Elle permet d'ajouter, supprimer, rechercher et afficher les pensionnaires du refuge, tout en assurant la sauvegarde des données.
## Fonctionnalités principales
### Menu principal
Propose différentes actions à l'utilisateur.
### Recherche d’un animal
- Recherche basée sur au moins deux critères parmi : nom, espèce ou tranche d'âge.

- Affiche les résultats ou un message si aucun animal ne correspond.

- L'utilisateur peut définir le nombre d'animaux à rechercher.

### Ajout d’un animal
- Saisie des informations : nom, espèce, année de naissance, poids, commentaires.

- Génération automatique d’un identifiant unique.

- Calcul automatique de l’âge, de la tranche d’âge, de la quantité de nourriture et de la charge de nettoyage.

- Le refuge peut accueillir jusqu’à 50 animaux.

### Adoption d’un animal
- Suppression d’un animal par son ID.

- Libération de la mémoire.

- Réorganisation du tableau dynamique.

### Statistiques du refuge
- Affichage du nombre total d’animaux.

- Répartition des animaux par espèce (tri décroissant).

- Répartition par tranche d’âge : bébé, jeune, adulte, senior.

### Nourriture quotidienne et nettoyage
- Calcul de la quantité totale de nourriture quotidienne selon l’espèce et l’âge.

- Affichage de la charge de nettoyage quotidienne et hebdomadaire selon les spécifications.

### Affichage des pensionnaires
- Affiche les informations de tous les pensionnaires du refuge à partir du fichier refuge.txt.

- Les données sont sauvegardées même après recompilation.

## Installation
### Prérequis
- Un environnement de développement C.

- Un compilateur comme gcc.

- make (optionnel, pour simplifier la compilation).

### Instructions
- Cloner le dépôt :
    - git clone https://github.com/Ameeshazaffer/ChenYI-Tech.git
- Accéder au dossier du projet :
    - cd chemin_jusqu'au_dossier_animaux 
- Compiler le programme (2 options) :
    - Avec make : 
         -  make
    - Sans make : 
         - gcc -c main.c
         - gcc -c animal.c
         -  gcc -c refuge.c
         -  gcc main.o animal.o refuge.o -o chenil


### Utilisation
- Exécuter le programme :
    - ./chenil
- Suivre les instructions affichées dans le terminal.

## Structure des fichiers
- `main.c` : Point d’entrée du programme principal.
- `animal.c / animal.h` : Gestion des données et opérations liées aux animaux.
- `refuge.c / refuge.h` : Gestion des données et opérations liées au refuge.
- `refuge.txt` : Fichier de sauvegarde des pensionnaires.
- `Makefile` : Script de compilation pour automatiser la création de l’exécutable.
- `README.md` : Guide de présentation et d'utilisation du projet.
- `rapport.pdf` : Brève description de l’équipe et du sujet.
