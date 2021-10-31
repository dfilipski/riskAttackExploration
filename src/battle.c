//
// Created by Dan Filipski on 10/29/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "battle.h"

/**
 * Simulate a Battle
 * @param attacker_armies
 *        A pointer to an integer containing the number of armies the attacker has.
 * @param defender_armies
 *        A pointer to an integer containing  number of armies the defender has.
 * @return A Player variable containing the winner
 */
BattleOutcome battle(int* attacker_armies, int* defender_armies, int attacker_die_count, int defender_die_count)
{

	if (*attacker_armies<attacker_die_count+1 ||
			*defender_armies<defender_die_count+1)//not allowed by risk's rules
		return ERROR;

	int attacker_dice[3], defender_dice[2];
	enum player winner;

	// roll attacker dice
	for (int i = 0; i<attacker_die_count; i++) {
		roll_dice(&attacker_dice[0], attacker_die_count);
	}

	// roll defender dice
	for (int i = 0; i<defender_die_count; i++) {
		roll_dice(&defender_dice[0], defender_die_count);
	}

	// compare
	winner = compare_highest(&attacker_dice[0], &defender_dice[0], attacker_die_count, defender_die_count);

	//Update army count, because the loser loses one army.
	if (winner==ATTACKER)
		*defender_armies -= 1;
	else if (winner==DEFENDER)
		*attacker_armies -= 1;

	// return result
	return winner;
}

/**
 * Roll dice and save the results in dice_array
 * @param dice_array
 *        A pointer to an array of at least length die_count
 * @param die_count
 *        An integer that is >= 1 and <= the length of dice_array
 */
void roll_dice(int* dice_array, int die_count)
{
	for (int i = 0; i<die_count; i++) {
		dice_array[i] = rand()%6+1;
	}
}

/**
 * Print the contents of the given array
 * @param array
 *        A pointer to an array of length length
 * @param length
 *        The length of the array
 */
void print_int_array(int* array, int length)
{
	printf("[");
	for (int i = 0; i<length; i++) {
		if (i!=length-1)
			printf("%d ", array[i]);
		else
			printf("%d", array[i]);
	}
	printf("]");
}

/**
 * Compare the highest element of attacker_dice to that of defender_dice
 * @param attacker_dice
 *        A pointer to an array of at least attacker_die_count elements
 * @param defender_dice
 *        A pointer to an array of at least defender_die_count elements
 * @param attacker_die_count
 *        An integer no greater than the length of attacker_dice
 * @param defender_die_count
 *        An integer, either 1 or 2
 * @return
 *        If there the highest elements are the same, DEFENDER is returned.
 *        If the the highest element is in attacker_dice, ATTACKER is returned.
 *        If the highest element is in defender_dice, DEFENDER is return.
 */
enum player compare_highest(int* attacker_dice, int* defender_dice, int attacker_die_count, int defender_die_count)
{
	int attacker_max_index, defender_max_index;

	attacker_max_index = find_max(&attacker_dice[0], attacker_die_count);
	defender_max_index = find_max(&defender_dice[0], defender_die_count);

	if (attacker_dice[attacker_max_index]>defender_dice[defender_max_index])
		return ATTACKER;
	else
		return DEFENDER;
}

/**
 * Return the maximum value of array
 * @param array A pointer to an array of at least one element
 * @param length The length of that array
 * @return The index of the greatest element
 */
int find_max(const int* array, int length)
{
	int max_index = 0;
	for (int i = 0; i<length; i++) {
		if (array[i]>array[max_index])
			max_index = i;
	}

	return max_index;
}

/**
 * Simulate num_battles battles and record results in Win Array.
 * Index 0 is attacker wins. Index 1 is defender wins. Index 3
 * is the total number of battles that occured, because one
 * side may lose all their armies before num_battles battles
 * have been completed.
 * @param win_array A two element array
 * @param num_battles The number of battles to simulate
 * @param pAttacker_armies Address of the attacker's army count
 * @param pDefender_armies Address of the defenders army count
 * @param attacker_die_count Number of dice attacker rolls
 * @param defender_die_count Number of dice defender rolls
 */
void simulate_war(int* win_array, int num_battles, int* pAttacker_armies, int* pDefender_armies, int attacker_die_count,
		int defender_die_count)
{
	//Fill win_array with zeros
	for (int i = 0; i<2; i++) {
		win_array[i] = 0;
	}

	//Simulate Battles
	for (int i = 0; i<num_battles; i++) {
		BattleOutcome winner = battle(pAttacker_armies, pDefender_armies, attacker_die_count, defender_die_count);

		//record result
		switch (winner) {
		case ATTACKER: win_array[0] += 1;
			win_array[2] += 1;
			break;
		case DEFENDER: win_array[1] += 1;
			win_array[2] += 1;
			break;
		default: //Stop once parameters are invalid
			return;
		}
	}

}