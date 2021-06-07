#include "header.h"

void saisirScooter ( scooter *s )
{
    printf("\nID ( unique ) = ");
    fflush(stdin);
    gets(s->ID);
    printf("\nKM ( float ) = ");
    scanf("%f",&s->Km);
    printf("\netat ( 1 dispo / 0 non ) =  ");
    scanf("%d",&s->etat);
    printf("\nDate : ");
    printf("\njour = ");
    scanf("%d",&s->t.jour);
    printf("\nmois = ");
    scanf("%d",&s->t.mois);
    printf("\nannee = ");
    scanf("%d",&s->t.annee);

}

cellule* chercherScooter ( liste l  , char ID[] )
{
    cellule *ptr ;
    ptr = l ;

    while (ptr )
    {
        if ( !strcmp(ptr->data.ID,ID ))
            return ptr ;
            else
            ptr = ptr->next ;
    }

    return ptr ;

}

liste ajouterScooter ( liste l , scooter s )
{
    
    liste nov ;
    nov = (struct cellule* )malloc(sizeof(struct cellule ));
    nov->data = s ;
    nov ->next = NULL ;
    if ( l )
    {
        cellule *ptr ;
        ptr = l ;

        while (ptr->next)
        {
             ptr = ptr->next ;
        }
        ptr->next = nov ;
    }
    else 
    l = nov ; 
    return l ;
}

void louerScooter ( liste l , char ID[] )
{
    cellule *temp ;

    temp = chercherScooter ( l , ID) ;

    if ( temp  )
    {
        if ( !(temp->data.etat) )
            printf("\n Deja en localisation ");
            else
            {
                printf("\nDispo ");
                temp->data.etat = 0 ;
            }
    }
    else
        printf("\nScooter n'existe pas ! veillez verifier l'ID ");
}

void afficherScooter ( liste l , char nomFichier[] )
{
    FILE *f = NULL ;
    f= fopen( nomFichier , "a" );

    if ( f == NULL )
        exit(EXIT_FAILURE );

    if ( l->next )
        {
            fprintf(f,"%s\t%f\t%d\t%d %d %d \n",l->data.ID , l->data.Km , l->data.etat , l->data.t.jour , l->data.t.mois , l->data.t.annee );
            afficherScooter(l->next , nomFichier );
        }
}

file init_file ( file f )
{
    f.head = NULL ;
    f.queu = NULL ;
    return f ;
}

file enfilerScooter ( liste l , file f , char ID[] )
{
    cellule *test ;
    test = chercherScooter ( l , ID );
    if ( test )
    {
        struct cellule *nov;
        nov = (struct cellule*)malloc(sizeof(struct cellule));
        nov->data = test->data ;
        nov->next = NULL;

        if ( f.head == NULL && f.queu == NULL )
            f.head = f.queu = nov ;
            else
            {
                f.queu->next = nov ;
                f.queu = nov;
            }
            return f ;
    }
    else
       {
         printf("\nScooter n'existe pas ! veillez verifier l'ID ");
         return f ;
       }
}
/*
void entretientScooter ( file *f , liste  l )
{

    if ( f->head == NULL && f->queu == NULL )
        printf("\nFile vide  ");
        else
        {
            printf("\nDate : ");
            printf("\njour = ");
            scanf("%d",&l->data.t.jour);
            printf("\nmois = ");
            scanf("%d",&l->data.t.mois);
            printf("\nannee = ");
            scanf("%d",&l->data.t.annee);
        }
}
*/


arbre insererScooters (arbre a , scooter s  )
{
        if ( a == NULL)
        {

                a = (struct root*)malloc(sizeof(struct root));
                a->data = s ;
                a->left = a->right = NULL;
            return a ;
        }
        else
         {
            if ( s.Km > a->data.Km)
                a->right = insererScooters(a->right , s );
                else
                a->left = insererScooters(a->left , s );

                return a;
        }
}

arbre construireArbre ( arbre a , liste l )
{
    if ( l )
    {
        cellule *ptr ;
        ptr = l ;
        while (ptr )
        {
            a = insererScooters(a , ptr->data );
            ptr = ptr->next ;
        }
        return a ;
    }
    else return NULL ;

}

arbre maxScooter ( arbre a )
{
   struct root *root = a ;
   while ( root ->right != NULL )
        root = root->right ;
   return root ;
}

void test_liste ( liste ptr )
{
    cellule *l ;
    l = ptr ;  
    while (l  )
    {
        printf("%s\t%f\t%d\t%d %d %d \n",l->data.ID , l->data.Km , l->data.etat , l->data.t.jour , l->data.t.mois , l->data.t.annee );
        l = l->next ; 
    }
    
}
