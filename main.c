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
   int* nb_total;
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
}

Animal** ajouter_Animal(Animal **tableau, int taille){



   return tableau;
}


Animal** enlever_Animal(Animal **tableau, int taille){



   return tableau;
}







int main{

   return 0;
}
