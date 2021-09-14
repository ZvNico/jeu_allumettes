#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef enum {
    J1,
    J2
}Joueur;
typedef enum {
    false,
    true
} Bool;

typedef enum {
    expert,
    naive
} Mode;

int play_human(int n_matches, Joueur joueur) {
    int n;
    printf("");
    return n;
}

int play_computer(int n_matches, Mode mode, int joueur) {
    int i;
    if (mode == expert) {
        for (i = 1; i < 4; ++i) {
            if ((n_matches - i - 1) % 4 == 0) {
                return i;
            }
        }
        return 1;
    } else if (mode == naive) {
        return 1 + rand() % 2;
    }
    return -1;
};

int menu() {
    char *game_name = "Jeu des allumettes";

}


int main() {
    srand(time(NULL)); // init limited randomness
    Mode mode;
    Bool quitter = false, j1_computer, j2_computer;
    int menu_input;
    while (quitter == false) {
        menu_input = menu();
        switch (menu_input) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                quitter = true;
        }
    }
    return 0;
}
