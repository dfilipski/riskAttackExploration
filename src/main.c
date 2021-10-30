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
    const int ATTACKER_ARMIES = 20;
    const int ATTACKER_DIE_COUNT = 3;
    const int DEFENDER_ARMIES = 20;
    const int DEFENDER_DIE_COUNT = 2;

    srand(time(0)); // NOLINT(cert-msc51-cpp)

    BattleOutcome winner = battle(ATTACKER_ARMIES, DEFENDER_ARMIES, ATTACKER_DIE_COUNT, DEFENDER_DIE_COUNT);

    // Display Results

    switch (winner) {
        case ATTACKER:
            printf("The attacker won the battle!\n");
            break;
        case DEFENDER:
            printf("The defender won the battle!\n");
            break;
        case TIE:
            printf("There was a tie!\n");
            break;
        default:
            printf("An error has occurred. The battle option may be invalid");
    }

    return 0;
}

