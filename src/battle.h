//
// Created by Dan Filipski on 10/29/21.
//

#ifndef RISKATTACKEXPLORATION_BATTLE_H
#define RISKATTACKEXPLORATION_BATTLE_H
typedef enum player {
  ATTACKER, DEFENDER, ERROR
} BattleOutcome;

BattleOutcome battle(int* attacker_armies, int* defender_armies, int attacker_die_count, int defender_die_count);

void roll_dice(int* dice_array, int die_count);

void print_int_array(int* array, int length);

enum player compare_highest(int* attacker_dice, int* defender_dice, int attacker_die_count, int defender_die_count);

int find_max(const int* array, int length);

void simulate_war(int* win_array, int num_battles, int* pAttacker_armies, int* pDefender_armies, int attacker_die_count,
		int defender_die_count);

#endif //RISKATTACKEXPLORATION_BATTLE_H
