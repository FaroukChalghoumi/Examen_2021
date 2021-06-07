#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs
typedef struct date
{
    int jour ;
    int mois ;
    int annee ;
}date ;

typedef struct scooter
{
    char ID[20]; // unique
    float Km ;
    int etat  ;
    date t ;
}scooter;

struct cellule
{
    scooter data ;
    struct cellule *next ;
};
typedef struct cellule cellule ;
typedef struct cellule *liste ;

struct file
{
    struct cellule *head ;
    struct cellule *queu ;
};

typedef struct file file ;

struct root
{
    scooter data ;
    struct root *left ;
    struct root *right ;
};

typedef struct root* arbre ;



//functions
void saisirScooter ( scooter *s );
cellule* chercherScooter ( liste l  , char ID[] );
liste ajouterScooter ( liste l , scooter s );
void louerScooter ( liste l , char ID[] );
void afficherScooter ( liste l , char nomFichier[] );
file init_file ( file f );
file enfilerScooter ( liste l , file f , char ID[] );
arbre insererScooters (arbre a , scooter s  );
arbre construireArbre ( arbre a , liste l );
arbre maxScooter ( arbre a );
void test_liste ( liste ptr );

#endif // HEADER_H_INCLUDED
