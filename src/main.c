/*********************************************************\
 * Name: Dan Filipski
 * Date: October 29, 2021
 * Purpose: This project will be used to recreate the risk
 *          battle system.
 \********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "battle.h"


int main(void) {
    int attacker_armies = 20;
    int attacker_die_count = 3;
    int defender_armies = 20;
    int defender_die_count = 2;

    srand(time(0)); // NOLINT(cert-msc51-cpp)

    BattleOutcome winner = battle(&attacker_armies, &defender_armies, attacker_die_count, defender_die_count);

    // Display Results

    switch (winner) {
        case ATTACKER:
            printf("The attacker won the battle!\n");
            break;
        case DEFENDER:
            printf("The defender won the battle!\n");
            break;
        default:
            printf("An error has occurred. The battle option may be invalid");
            break;
    }
    printf("Armies\n"
           "Attacker: %d\n"
           "Defender: %d\n", attacker_armies, defender_armies);

    return 0;
}

