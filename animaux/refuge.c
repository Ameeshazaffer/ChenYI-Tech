// FICHIER refuge.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "animal.h"
#include "refuge.h"

// Fonction qui ajoute un nouvel animal dans le tableau du refuge
Animal** ajouter_Animal(Animal **tableau, int *taille, Animal *a){
if((*taille + 1) >= 50){ // Vérifie si le nombre d'animaux dans le refuge atteint la capacité maximale
    printf("\nIl n'y a plus de place dans le refuge.\n\n");
}else{
    tableau = realloc(tableau, (*taille + 1) * sizeof(Animal*)); //Redimensionnement du tableau pour accueillir un animal de plus
    if (tableau == NULL) { // Si realloc échoue, on affiche un message d'erreur et on quitte le programme
        printf("\nErreur d'allocation de la memoire.\n");
        exit(1);
    }
    tableau[*taille] = a; // Ajout du nouvel animal à la fin du tableau
    (*taille)++; // Incrémentation de la taille du refuge
    printf("\n\nInformations du nouvel animal:\n\n");
    afficher(a);
}
    return tableau; // Retour du tableau mis à jour
}

// Fonction pour enlever un animal du tableau en fonction de son identifiant
Animal** enlever_Animal(Animal **tableau, int *taille, int id) {
int index = -1; // Variable pour stocker l'index de l'animal trouvé, initialisé à -1 si non trouvé
for(int i = 0; i < *taille; i++){ // Boucle qui parcourt le tableau pour rechercher l'animal avec l'identifiant correspondant
    if((*(tableau + i))->num_id == id){
        index = i;
        break;
    }
}

if(index == -1){ // Si l'index est toujours -1, cela signifie que l'animal n'a pas été trouvé
    printf("\n\nCet animal n'a pas ete trouve.\n\n");
}else{ // Si l'animal est trouvé, on affiche ses informations avant de le supprimer
    printf("\n\nInformations de l'animal adopte :\n\n");
    afficher(*(tableau + index));
    // Libération de la mémoire allouée pour l'animal (nom, espèce, commentaire)
    free((*(tableau + index))->nom);
    free((*(tableau + index))->espece);
    free((*(tableau + index))->commentaire);
    free(*(tableau + index));
    // Décalage des éléments restants dans le tableau pour combler le vide laissé par l'animal supprimé
    for(int j = index; j < (*taille - 1); j++){
        *(tableau + j) = *(tableau + (j + 1));
    }
    (*taille)--; // Décrémentation de la taille du refuge
    if (*taille > 0) { // Si la taille du tableau est supérieure à 0, on tente de réalouer la mémoire
    tableau = realloc(tableau, (*taille) * sizeof(Animal*));
        if (tableau == NULL) {// Si realloc échoue, on affiche un message d'erreur et on quitte le programme
            printf("\nErreur d'allocation de la memoire.\n");
            exit(1);
        }
    }else{ // Si la taille du tableau est 0, on libère la mémoire du tableau et on le met à NULL
    free(tableau);
    tableau = NULL;
    }

}
    return tableau; // Retour du tableau mis à jour
}


// Fonction qui recherche un animal dans le tableau du refuge selon son nom et/ou son espèce et/ou sa tranche d'âge
void rechercher_Animal(Animal **tableau, int taille, char *nom, char* espece, char* tranche_age){
int trouve = 0; //Variable qui indique si l'animal a été trouvé

// Parcours du tableau des animaux dans le refuge
for(int i = 0 ; i < taille ; i++){
if(strcmp(nom,"X")!=0){ // Si le nom n'est pas "X" (l'utilisateur souhaite rechercher par nom)
    if(strcmp(espece,"X")!=0){ // Si l'espèce n'est pas "X" (l'utilisateur souhaite rechercher par espèce)
        if(strcmp(tranche_age,"X")!=0){ // Si la tranche d'âge n'est pas "X" (l'utilisateur souhaite rechercher par tranche d'âge)
            // Recherche d'un animal avec le nom, l'espèce et la tranche d'âge correspondants + affichage
            if(strcmp(nom,(*(tableau + i))->nom)==0 && strcmp(espece,(*(tableau + i))->espece)==0 && strcmp(tranche_age,(*(tableau + i))->tranche_age)==0){
                printf("\n\nInformations de l'animal recherche :\n\n");
                afficher(*(tableau + i));
                trouve = 1;
            }
        }else{ // Si la tranche d'âge est "X", on ignore ce critère
            // Recherche d'un animal avec le nom et l'espèce correspondants + affichage
            if(strcmp(nom,(*(tableau + i))->nom)==0 && strcmp(espece,(*(tableau + i))->espece)==0){
                printf("\n\nInformations de l'animal recherche :\n\n");
                afficher(*(tableau + i));
                trouve = 1;
            }
        }
    }else{ // Si l'espèce est "X", on ignore ce critère
        if(strcmp(tranche_age,"X")!=0){
            // Recherche d'un animal avec le nom et la tranche d'âge correspondants + affichage
            if(strcmp(nom,(*(tableau + i))->nom)==0 && strcmp(tranche_age,(*(tableau + i))->tranche_age)==0){
                printf("\n\nInformations de l'animal recherche :\n\n");
                afficher(*(tableau + i));
                trouve = 1;
            }
        }
    }
}else{ // Si le nom est "X", on ignore ce critère
    if(strcmp(espece,"X")!=0){
        if(strcmp(tranche_age,"X")!=0){
            // Recherche d'un animal avec l'espèce et la tranche d'âge correspondants + affichage
            if(strcmp(espece,(*(tableau + i))->espece)==0 && strcmp(tranche_age,(*(tableau + i))->tranche_age)==0){
                printf("\n\nInformations de l'animal recherche :\n\n");
                afficher(*(tableau + i));
                trouve = 1;

            }
        }
    }
}

}

// Si aucun animal n'a été trouvé
if(trouve==0){
    printf("\n\nL'animal recherche n'a pas ete trouve.\n");
}
}


// Fonction qui affiche le nombre d'animaux dans chaque espèce, trié par nombre décroissant
void tableau_espece(Animal **tableau, int taille){
int nb_chiens = 0, nb_chats = 0, nb_autruches = 0, nb_hamsters = 0, i, j;
printf("\nIl y a %d animal/animaux dans le refuge.\n\n", taille);

// Parcours de chaque animal dans le tableau pour compter le nombre d'animaux de chaque espèce
for(i = 0; i < taille; i++){
    if(strcmp((*(tableau + i))->espece, "chien") == 0){
        nb_chiens++;
    }else if (strcmp((*(tableau + i))->espece, "chat") == 0){
        nb_chats++;
    }else if (strcmp((*(tableau + i))->espece, "autruche") == 0){
        nb_autruches++;
    }else if (strcmp((*(tableau + i))->espece, "hamster") == 0){
        nb_hamsters++;
    }
}

// Création d'un tableau contenant les espèces et leur nombre d'animaux respectifs
Tableau_espece tab[4] = {{"chien", nb_chiens}, {"chat", nb_chats}, {"autruche", nb_autruches}, {"hamster", nb_hamsters}};

// Tri par ordre décroissant du nombre d'animaux
for(i = 0; i < 4 - 1; i++){
    for(j = 0; j < 4 - i - 1; j++){
        if(tab[j].nb < tab[j + 1].nb){
            Tableau_espece tmp = tab[j];
            tab[j] = tab[j + 1];
            tab[j + 1] = tmp;
        }
    }
}

// Affichage de chaque espèce et du nombre d'animaux correspondants
printf("_______________________________________NOMBRE D'ANIMAUX DE CHAQUE ESPECE__________________________________\n");
for(i = 0; i < 4; i++){
    printf("%s : %d\n", tab[i].espece, tab[i].nb);
}
}

// Fonction qui affiche le nombre d'animaux dans chaque tranche d'âge (bébé, jeune, adulte, senior)
void tableau_age(Animal **tableau, int taille){
int nb_bebes = 0, nb_jeunes = 0, nb_adultes = 0, nb_seniors = 0, i;

// Parcours de chaque animal dans le tableau pour compter le nombre d'animaux dans chaque tranche d'âge
for(i = 0; i < taille; i++){
    if(strcmp((*(tableau + i))->tranche_age, "bebe") == 0) {
        nb_bebes++;
    }else if(strcmp((*(tableau + i))->tranche_age, "jeune") == 0) {
        nb_jeunes++;
    }else if(strcmp((*(tableau + i))->tranche_age, "adulte") == 0) {
        nb_adultes++;
    }else if(strcmp((*(tableau + i))->tranche_age, "senior") == 0) {
        nb_seniors++;
    }
}

// Création d'un tableau contenant les tranches d'âge et leur nombre d'animaux respectifs
Tableau_age tab[4] = {{"bebes", nb_bebes}, {"jeunes", nb_jeunes}, {"adultes", nb_adultes}, {"seniors", nb_seniors}};
printf("___________________________________NOMBRE D'ANIMAUX PAR TRANCHE D'AGE _____________________________________\n");

// Affichage de chaque tranche d'âge et du nombre d'animaux correspondants
for(i = 0; i < 4; i++){
    printf("%s : %d\n", tab[i].tranche_age, tab[i].nb);
}
printf("___________________________________________________________________________________________________________\n");
}

// Fonction pour sauvegarder le refuge dans un fichier
void sauvegarder_refuge(Animal **refuge, int taille, const char *fichier) {
FILE *file = fopen(fichier, "w"); // Ouvre le fichier en mode écriture
if (file == NULL) { // Si l'ouverture échoue
    printf("Erreur lors de l'ouverture du fichier pour sauvegarde.\n");
    return;
}

// Parcourt chaque animal du refuge et écrit ses informations dans le fichier
for (int i = 0; i < taille; i++) {
    fprintf(file, "ID: %d\n", (*(refuge + i))->num_id);
    fprintf(file, "NOM: %s\n", (*(refuge + i))->nom);
    fprintf(file, "ESPECE: %s\n", (*(refuge + i))->espece);
    fprintf(file, "ANNEE DE NAISSANCE: %d\n", (*(refuge + i))->naissance);
    fprintf(file, "AGE: %d\n", (*(refuge + i))->age);
    fprintf(file, "POIDS: %.2f\n", (*(refuge + i))->poids);
    fprintf(file, "TRANCHE D'AGE: %s\n", (*(refuge + i))->tranche_age);
    fprintf(file, "QUANTITES DE NOURRITURE: %.2f\n", (*(refuge + i))->quantites_nourriture);
    fprintf(file, "TRAVAIL JOURNALIER: %d\n", (*(refuge + i))->travail_journalier);
    fprintf(file, "TRAVAIL HEBDOMADAIRE: %d\n", (*(refuge + i))->travail_hebdomadaire);
    fprintf(file, "COMMENTAIRE: %s\n", (*(refuge + i))->commentaire);
}

    fclose(file);// Ferme le fichier après l'écriture
}


// Fonction pour charger les données du refuge à partir d'un fichier
Animal** charger_refuge(int *taille, const char *fichier) {
FILE *file = fopen(fichier, "r"); // Ouvre le fichier en mode lecture
if (file == NULL) { // Si le fichier n'existe pas ou ne peut être ouvert
    printf("Refuge vide : creation d'un nouveau refuge.\n");
    *taille = 0;
    return NULL;
}

// Compter le nombre total de lignes dans le fichier
int lignes = 0;
char buffer[512];
while (fgets(buffer, sizeof(buffer), file)) {
    lignes++;
}
rewind(file);

*taille = lignes / 11; // Chaque animal prend 11 lignes

Animal **refuge = malloc(*taille * sizeof(Animal*)); // Alloue un tableau de pointeurs pour les animaux

// Lecture des données des animaux depuis le fichier
for (int i = 0; i < *taille; i++) {
    // Alloue de la mémoire pour chaque animal
    (*(refuge + i)) = malloc(sizeof(Animal));
    // Alloue de la mémoire pour les chaînes de caractères
    (*(refuge + i))->nom = malloc(50);
    (*(refuge + i))->espece = malloc(50);
    (*(refuge + i))->tranche_age = malloc(50);
    (*(refuge + i))->commentaire = malloc(256);
    // Utilise fscanf pour lire les données dans le fichier et les stocker dans chaque animal
    fscanf(file, "%d\n", &(*(refuge + i))->num_id);
    fscanf(file, "%49[^\n]\n", (*(refuge + i))->nom);
    fscanf(file, "%49[^\n]\n", (*(refuge + i))->espece);
    fscanf(file, "%d\n", &(*(refuge + i))->naissance);
    fscanf(file, "%d\n", &(*(refuge + i))->age);
    fscanf(file, "%f\n", &(*(refuge + i))->poids);
    fscanf(file, "%49[^\n]\n", (*(refuge + i))->tranche_age);
    fscanf(file, "%f\n", &(*(refuge + i))->quantites_nourriture);
    fscanf(file, "%d\n", &(*(refuge + i))->travail_journalier);
    fscanf(file, "%d\n", &(*(refuge + i))->travail_hebdomadaire);
    fscanf(file, "%255[^\n]\n", (*(refuge + i))->commentaire);
}

fclose(file);
    return refuge; // Retourne le tableau d'animaux
}
