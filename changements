#include <stdio.h> 
#include <stdlib.h>
#include "constants.h"


typedef struct{
   int num_id;
   char* nom;
   char* espece;
   char* naissance;
   float poids;
   char* commentaire;
}Animal;

typedef struct{
   Animal **tableau; //voir si double pointeurs//
}refuge;

int menu(){
   int option;
   printf("Veuillez choisir l'action a realiser./n");
   printf("1.Rechercher un/des animaux./n");
   printf("2.Ajouter un animal./n");
   printf("3.Adopter un animal./n");
   scanf("%d",&option);
return option;
}

void afficher(Animal a){
   printf("NOM : %d\n",a.num_id);
   printf("NOM : %s\n",a->nom);
   printf("ESPECE : %s\n",a->espece);
   printf("DATE DE NAISSANCE : %s\n",a->naissance);
   printf("POIDS : %.2f\n",a.poids);
   printf("COMMENTAIRE : %s\n",a->commentaire);
}

void rechercher_Animal(Animal **tableau, int taille ,char* nom , char* espece , int type_age){
   for(int i = 0 ; i < taille ; i++){
      if(strcmp(tableau[i]->nom,nom)==0){
         afficher(tableau[i]); 
      }else if(strcmp(tableau[i]->nom,nom)==0){
         afficher(tableau[i]); 
      }else if(){

   }
}//Pas sur : comment faire plusieurs animaux ? commennt faire le type d'age ?//

Animal** ajouter_Animal(Animal **tableau, int *taille, Animal a){
if((*taille+1) > 50){
   printf("Il n'y a plus de place dans le refuge.\n")
   return 1;
}else if((*taille+1) <= 50){
   tableau = realloc(tableau,(*taille+1));
   strcpy(tableau[(*taille+1)]->nom,a->nom);
   strcpy(tableau[(*taille+1)]->espece,a->espece);
   strcpy(tableau[(*taille+1)]->naissance,a->naissance);
   strcpy(tableau[(*taille+1)]->commentaire,a->commentaire);
   tableau[(*taille+1)].poids = a.poids;
   tableau[(*taille+1)].num_id = a.num_id;
   //tableau[(*taille+1)] = a Pas sur : depend de s'il faut copier les elemnts du tableau un par un//
   *taille++;
}
   return tableau;
}


Animal** enlever_Animal(Animal **tableau, int *taille,int id){
   int indexe = -1;
   tableau = realloc(tableau,(*taille-1));
   for(int i = 0 ; i < taille ; i++){
      if(tableau[i].num_id == id){
         indexe = i;
      }
   }
   if(indexe!=-1){
      for(int j = indexe+1 ; j < (*taille-1) ; j++){
         tableau[j] = tableau[j-1];
      }
   }else{
      printf("Cet animal n'a pas ete trouve.\n");
   }
   *taille--;
   return tableau;
}



1 compter le nb d'animaux d'une espece 
1 compter le nb d'animaux d'une tranche d'age 


int main{

   return 0;
}
