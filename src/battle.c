//
// Created by Dan Filipski on 10/29/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "battle.h"

/**
 * Simulate a Battle
 * @param attacker_armies
 *        The number of armies the attacker has.
 * @param defender_armies
 *        The number of armies the defender has.
 * @return A Player variable containing the winner
 */
enum player battle(int attacker_armies, int defender_armies, int attacker_die_count, int defender_die_count) {

    if (attacker_armies < attacker_die_count + 1 ||
        defender_armies < defender_die_count + 1)//not allowed by risk's rules
        return ERROR;

    int attacker_dice[3], defender_dice[2];
    enum player winner;

    // roll attacker dice
    for (int i = 0; i < attacker_die_count; i++) {
        roll_dice(&attacker_dice[0], attacker_die_count);
    }

    // roll defender dice
    for (int i = 0; i < defender_die_count; i++) {
        roll_dice(&defender_dice[0], defender_die_count);
    }

    // compare
    winner = compare_highest(&attacker_dice[0], &defender_dice[0], attacker_die_count, defender_die_count);

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
void roll_dice(int *dice_array, int die_count) {
    for (int i = 0; i < die_count; i++) {
        dice_array[i] = rand() % 6 + 1;
    }
}

/**
 * Print the contents of the given array
 * @param array
 *        A pointer to an array of length length
 * @param length
 *        The length of the array
 */
void print_int_array(int *array, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        if (i != length - 1)
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
 *        An integer no greater than the length of defender_dice
 * @return
 *        If there the highest elements are the same, TIE is returned.
 *        If the the highest element is in attacker_dice, ATTACKER is returned.
 *        If the highest element is in defender_dice, DEFENDER is return.
 */
enum player compare_highest(int *attacker_dice, int *defender_dice, int attacker_die_count, int defender_die_count) {
    int attacker_max, defender_max;
    attacker_max = find_max(&attacker_dice[0], attacker_die_count);
    defender_max = find_max(&defender_dice[0], defender_die_count);

    if (attacker_max > defender_max)
        return ATTACKER;
    else if (defender_max > attacker_max)
        return DEFENDER;
    else
        return TIE;
}

/**
 * Return the maximum value of array
 * @param array A pointer to an array of at least one element
 * @param length The length of that array
 * @return The value of the greatest element
 */
int find_max(const int *array, int length) {
    int max = array[0];
    for (int i = 0; i < length; i++) {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}