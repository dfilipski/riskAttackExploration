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

    int num_battles = 50;

    int win_stats[3];//{attacker_wins, defender_wins}

    srand(time(0)); // NOLINT(cert-msc51-cpp)

    simulate_war(&win_stats[0], num_battles, &attacker_armies, &defender_armies, attacker_die_count,
                 defender_die_count);

    printf("╔════════════════════════╦════════════════════════════╗\n"
           "║Attacker Wins: %8d ║ Attacker Win Rate: %8.4f║\n"
           "╠════════════════════════╬════════════════════════════╣\n"
           "║Defender Wins: %8d ║ Defender Win Rate: %8.4f║\n"
           "╚════════════════════════╩════════════════════════════╝\n", win_stats[0], win_stats[0] / (double) win_stats[2],
           win_stats[1], win_stats[1] / (double) win_stats[2]);

    return 0;
}

