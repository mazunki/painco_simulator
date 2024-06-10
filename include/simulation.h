#ifndef SIMULATION_H
#define SIMULATION_H
#include <stdbool.h>
#include "character.h"

typedef struct {
        unsigned long long total_time;
        int battle_count;
        int player_wins;
        int perfect_wins;
        int opponent_wins;
	int drops;
} Summary;

long simulate_battle(Character *player, Character *opponent);
void simulate_battles(Summary *s, Character player, Character enemy, int n);
void print_target(Character c);

#endif

/* vim: set sw=8 ts=8 expandtab*/

