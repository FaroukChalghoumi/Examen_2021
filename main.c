#include "header.h"
int main()
{
    //déclaration des variables
    int choix;
    liste l = NULL ;
    file f = init_file( f);
    arbre a = NULL ; 
    scooter s ;
    char ID[20];

    //affichage du menu
    do
    {
        do
        {
            printf("\n-------------------MENU------------------------\n");
            printf("---1.Ajouter nov Scooter \n");
            printf("---2.Louer Scooter \n");
            printf("---3.Afficher liste Scooter ( fichier ) \n");
            printf("---4.Enfiler Scooter \n");
            printf("---5.Entretient Scooter \n");
            printf("---6.Construire Arbre \n");
            printf("---7.Afficher le scooter ayant max KM  \n");
            printf("---0.Quitter-----------------------------------\n");
            printf("choix = \n");
            scanf("%d",& choix);
        } while ((choix>7)||(choix<0));
        
    //traitement des choix
        switch (choix)
        {
            case 1:
            if ( l )
            {
                do
                {
                    printf("\nVeillez Saisir un ID unique pour chaque Scooter ! Merci . ");
                    saisirScooter(&s);
                } while (chercherScooter(l , s.ID ));
            }
                else 
                    saisirScooter(&s);
            l = ajouterScooter(l , s );
            test_liste ( l );
            break;
            case 2:
            printf("\nID ( unique ) = ");
            fflush(stdin);
            gets(ID);
            louerScooter(l , ID );
            test_liste ( l );
            break;
            case 3:
            afficherScooter( l , "backup.txt");
            break;
            case 4:
            printf("\nID ( unique ) = ");
            fflush(stdin);
            gets(ID);
            f = enfilerScooter ( l , f , ID );
            break;
            case 5:
            //traitement
            break;
            case 6:
            a = construireArbre ( a , l );
            break;
            case 7 : 
            a = maxScooter ( a );
            printf("\nMAX  = %f " , a->data.Km );
            break; 
        }
    } while (choix!=0);
    
    return 0;
}
