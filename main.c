#include <stdio.h>

int menu() {

    printf("\n=============================================================\n");
    printf("\n\t\t\t\t C LANGUAGE 2021-2022\n\n");
    printf("\n\t\t\tProjet  : Jeux des allumettes \n\n");
    printf("\n\t Project by Nicolas Baconnier and Rania Dahane \n\n");

    printf("Vous allez avoir trois menus. \n");
    printf("Vous choisirez d'abord si vous voulez voir les regles du jeu ou non,\n");
    printf("puis le nombre d'allumettes a utiliser et enfin le nombre de joueurs\n");

    int choix;
    printf("\n\t ======= Menu =======\n\n");
    printf("\t1.Jouer\n");
    printf("\t2.Voir les regles du jeu\n");
    printf("\t3.Voir les credits\n");
    printf("\t4.Quitter\n");
    printf("\n     Que faire ? ");
    scanf("%d", &choix);
    printf("\n");
    return choix;
}
//initialisation du menu1
int menu_access_service(){
    int choix2;
    printf("\n\t ======= Choix des joueurs  =======\n\n");
    printf("\t1 Joueur\n");
    printf("\t2 Joueurs\n");
    printf("\t3. Quitter\n");
    printf("\n     Que faire? ");
    scanf("%d", &choix2);
    printf("\n");
    return choix2;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    // Menu
    int mainmenu = menu();

    do
    {
        if (mainmenu==1)
        {
            int case1 = menu_access_service();
            int answer;
            do
            {
                switch(case1)
                {
                    case 1 :

                        do
                        {
                            printf("\n\n Voulez-vous retourner au menu \n\n\t 1. Oui \t\t 2. Non\n\n\n");
                            printf("Que faire?  ");
                            scanf("%d", &answer);
                            if (answer == 1 )
                            {
                                mainmenu = menu();
                            } else if (answer == 2)
                            {
                                case1 = menu_access_service();
                            }
                        } while ((answer != 1) && (answer != 2));

                        break;

                    case 2 :

                        do
                        {
                            printf("\n\n Voulez-vous retourner au menu \n\n\t 1. Oui \t\t 2. Non\n\n\n");
                            printf("Que faire ?  ");
                            scanf("%d", &answer);
                            if (answer == 1 )
                            {
                                mainmenu = menu();
                            } else if (answer == 2)
                            {
                                case1 = menu_access_service();
                            }
                        } while ((answer != 1) && (answer != 2));
                        break;

                    case 3 :


                        do
                        {
                            printf("\n\n Voulez-vous retourner au menu \n\n\t 1. Oui \t\t 2. Non\n\n\n");
                            printf("Que faire ?  ");
                            scanf("%d", &answer);
                            if (answer == 1 )
                            {
                                mainmenu = menu();
                            } else if (answer == 2)
                            {
                                case1 = menu_access_service();
                            }
                        } while ((answer != 1) && (answer != 2));

                        break;

                    case 4 :
                        printf("\n\n\t\t Thanks for spending time on our project!!\n");
                        printf("\n\t\t\t See you soon !!:)\n");
                        printf("\n\t - Nicolas et Rania ❤ \n\n");

                        break;

                    default :
                        printf("\n\t\t\t\t ERROR \n\n");
                        printf("\n\t REDIRECTION TO THE MAIN MENU  \n\n");
                        break;
                }
            }while ((case1 != 1) && (case1 != 2) && (case1 != 3) && (case1 != 4));
        }

        else if (mainmenu==3)
        {
            printf("\n\t ======= Credit  =======\n\n");

            mainmenu=menu();
        }
        else if (mainmenu==4)
        {
            printf("\n\n\t\t Thanks for spending time on our project!!\n");
            printf("\n\t\t\t See you soon !!:)\n");
            printf("\n\t - Nico et Rania ❤ \n\n");

        }
        else
        {
            printf("\n\t\t\t\t ERROR \n\n");
            printf("\n\t REDIRECTION TO THE MAIN MENU  \n\n");
            mainmenu=menu();
            break;
        }

    }while ((mainmenu != 1) || (mainmenu != 2) ||(mainmenu != 3) ||(mainmenu != 4));
    return 0;
}
