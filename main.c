#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    false,
    true
} Bool;

typedef enum {
    expert,
    naive
} Mode;

typedef struct Joueur {
    char name[31];
    Bool is_computer;
    Mode mode;
    unsigned int score;
} Joueur;


unsigned int play_human(int n_matches, Joueur *joueur) {
    int n;
    do {
        printf("%s - Nombre d'allumettes a enlever: ", joueur->name);
        scanf("%u", &n);
        fflush(stdin);
    } while ((n_matches - n < 0) || n < 1 || n > 3);
    return n;
}

unsigned int play_computer(int n_matches, Joueur *joueur) {
    int i;
    if (joueur->mode == expert) {
        for (i = 1; i < 4; ++i) {
            if ((n_matches - i - 1) % 4 == 0) {
                return i;
            }
        }
        return 1;
    } else if (joueur->mode == naive) {
        return 1 + rand() % 2;
    }
};

unsigned int menu() {
    int choix;
    do {
        printf("\n\t ======= Menu =======\n\n"
               "\t1.Jouer\n"
               "\t2.Voir les regles du jeu\n"
               "\t3.Voir les credits\n"
               "\t4.Quitter\n"
               "\tQue faire ?\n\t-> ");
        scanf("%d", &choix);
        fflush(stdin);
    } while (choix != 1 && choix != 2 && choix != 3 && choix != 4);
    return choix;
}


int main() {
    srand(time(NULL)); // init limited randomness
    fflush(stdin);
    unsigned n_matches, i, menu_input, play;
    Bool quitter = false;
    Joueur *J1, *J2;
    int turn;
    J1 = malloc(sizeof(Joueur));
    J2 = malloc(sizeof(Joueur));
    Joueur *joueurs[2] = {J1, J2};
    printf("\n\t\t C LANGUAGE 2021-20202\n\n"
           "Projet: Jeux des allumettes\n"
           "\tpar Nicolas Baconnier et Rania Dahane\n\n"
           "Vous allez avoir trois menus. \n"
           "Vous choisirez d'abord si vous voulez voir les regles du jeu ou non,\n"
           "puis le nombre d'allumettes a utiliser et enfin le nombre de joueurs\n");
    Mode mode;
    while (quitter == false) {
        menu_input = menu();
        switch (menu_input) {
            case 1:
                turn = 0;
                for (i = 0; i < 2; ++i) {
                    joueurs[i]->score = 0;
                    do {
                        printf("J%d:\n\t1.Human\n\t2.Computer\n\t-> ", i + 1);
                        scanf("%u", &joueurs[i]->is_computer);
                        fflush(stdin);
                        joueurs[i]->is_computer--;
                    } while (joueurs[i]->is_computer != true && joueurs[i]->is_computer != false);
                    if (joueurs[i]->is_computer == true) {
                        sprintf(joueurs[i]->name, "Ordi %d", i + 1);
                        do {
                            printf("Mode:\n\t1.expert\n\t2.naive\n\t-> ");
                            scanf("%u", &joueurs[i]->mode);
                            fflush(stdin);
                        } while (joueurs[i]->mode != expert && joueurs[i]->mode != naive);
                        joueurs[i]->mode--;
                    } else {
                        printf("J%d Pseudo: \n\t-> ", i + 1);
                        scanf("%s", joueurs[i]->name);
                    }
                }
                do {
                    printf("Nombre d'allumettes: ");
                    scanf("%u", &n_matches);
                    fflush(stdin);
                } while (n_matches < 0);
                for (i = 0; i < 2; ++i) {
                    if (joueurs[i]->is_computer) {
                        printf("%s - ", joueurs[i]->name);
                    } else {
                        printf("J%d - ", i + 1);
                        printf("%s", joueurs[i]->name);
                    }
                    if (joueurs[i]->is_computer) {
                        printf("niveau %u", joueurs[i]->mode + 1);
                    }
                    if (i == 0) {
                        printf(" vs ");
                    } else {
                        printf(", avec %d allumettes au depart.\n", n_matches);
                    }
                }
                while (n_matches > 0) {
                    for (i = 0; i < n_matches; ++i) {
                        printf("| ");
                    };
                    printf("\tIl reste %d allumettes\n", n_matches);
                    if (joueurs[turn % 2]->is_computer) {
                        play = play_computer((int) n_matches, joueurs[turn % 2]);
                        printf("%s - Nombre d'allumettes a enlever : %d\n", joueurs[turn % 2]->name, play);
                    } else {
                        play = play_human((int) n_matches, joueurs[turn % 2]);
                    }
                    n_matches -= play;
                    turn++;
                }
                joueurs[turn % 2]->score++;
                printf("%s %d - %d %s\n", joueurs[0]->name, joueurs[0]->score, joueurs[1]->score, joueurs[1]->name);
                break;
            case 2:
                printf("Le but du jeu est simple\n\n"
                       "Ce jeu se joue a deux. Vous avez un nombre n d'allumettes.\n"
                       "A tour de role, chacun des deux joueurs enleve entre 1 et 3 allumettes selon ce qu'il souhaite. Le perdant est celui qui doit enlever la derniere allumette\n\n"
                       "");
                break;
            case 3:
                printf("Pas encore implémenté ! ");
                break;
            case 4:
                quitter = true;
        }
    }
    free(J1);
    free(J2);
    return 0;
}
