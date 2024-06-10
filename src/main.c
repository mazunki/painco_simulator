#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "character.h"
#include "data.h"
#include "simulation.h"

void format_time(unsigned long long t, char *buffer, size_t buffer_size) {
    int ttdays = t / 86400;
    int tthours = (t % 86400) / 3600;
    int ttminutes = (t % 3600) / 60;
    int ttseconds = t % 60;

    snprintf(buffer, buffer_size, "%dd %02dh %02dm %02ds", ttdays, tthours, ttminutes, ttseconds);
}

void print_summary(Summary s) {
    unsigned long long t_seconds = s.total_time / 1000;
    char time_buffer[50];

    format_time(t_seconds, time_buffer, sizeof(time_buffer));
    printf("Total battle time: %s\n", time_buffer);

    printf("Number of battles: %'d\n", s.battle_count);

    printf("Player wins: %d (%.5f %%)\n", s.player_wins, 100 * (double)s.player_wins / (double)s.battle_count);
    printf("Perfect player wins: %d (%.5f %%)\n", s.perfect_wins, 100 * (double)s.perfect_wins / (double)s.battle_count);
    printf("Opponent wins: %d (%.5f %%)\n", s.opponent_wins, 100 * (double)s.opponent_wins / (double)s.battle_count);
    printf("\n");

    format_time(((double)t_seconds) / s.player_wins, time_buffer, sizeof(time_buffer));
    printf("Time per kill: %s\n", time_buffer);


    if (s.drops == 0) return;

    printf("Items dropped: %d (%.5f %%)\n", s.drops, 100 * (double)s.drops / (double)s.battle_count);

    format_time(((double)t_seconds) / s.drops, time_buffer, sizeof(time_buffer));
    printf("Average time per drop: %s\n", time_buffer);
}


void do_simulation(Character player, Character target) {
	Summary s = {0};
	printf("<=== ");
	simulate_battles(&s, player, target, NUMBER_OF_SIMULATIONS);
	print_summary(s);
	printf("===>\n\n");
};

int main() {
	srand(time(NULL));
	setlocale(LC_NUMERIC, "");

	do_simulation(player_lv1_stab, golbin);
	do_simulation(player_lv1_slash, golbin);
	do_simulation(player_lv1_block, golbin);

	/*
	do_simulation(player_lv1_stab, ranged_golbin);
	do_simulation(player_lv1_slash, ranged_golbin);
	do_simulation(player_lv1_block, ranged_golbin);

	do_simulation(player_lv1_stab, steel_knight_special);
	do_simulation(player_lv1_slash, steel_knight_special);
	do_simulation(player_lv1_block, steel_knight_special);
	*/

	return 0;
}
