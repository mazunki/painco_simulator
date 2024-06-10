#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "character.h"
#include "data.h"
#include "simulation.h"

void print_summary(Summary s) {
	unsigned long long t_seconds = s.total_time/1000;

	int days = t_seconds / 86400;
	int hours = (t_seconds % 86400) / 3600;
	int minutes = (t_seconds % 3600) / 60;
	int seconds = t_seconds % 60;

	printf("Total battle time: %dd %02dh %02dm %02ds\n", days, hours, minutes, seconds);
	printf("Number of battles: %'d\n", s.battle_count);
	printf("Player wins: %d (%.5f %%)\n", s.player_wins, 100*(double)s.player_wins/(double)s.battle_count);
	printf("Opponent wins: %d (%.5f %%)\n", s.opponent_wins, 100*(double)s.opponent_wins/(double)s.battle_count);
	printf("\n");

	unsigned long long tpk = ((double)t_seconds)/s.player_wins;
	int ttdays = tpk / 86400;
	int tthours = (tpk % 86400) / 3600;
	int ttminutes = (tpk % 3600) / 60;
	int ttseconds = tpk % 60;

	printf("Time per kill: %dd %02dh %02dm %02ds\n", ttdays, tthours, ttminutes, ttseconds);
	
	if (s.drops == 0) return;

	unsigned long long tpd = ((double)t_seconds)/s.drops;
	int dddays = tpd / 86400;
	int ddhours = (tpd % 86400) / 3600;
	int ddminutes = (tpd % 3600) / 60;
	int ddseconds = tpd % 60;

	printf("Items dropped: %d (%.5f %%)\n", s.drops, 100*(double)s.drops/(double)s.battle_count);
	printf("Average time per drop: %dd %02dh %02dm %02ds\n", dddays, ddhours, ddminutes, ddseconds);
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

	/*
	do_simulation(player_lv1_stab, golbin);
	do_simulation(player_lv1_slash, golbin);
	do_simulation(player_lv1_block, golbin);
	*/

	/*
	do_simulation(player_lv1_stab, ranged_golbin);
	do_simulation(player_lv1_slash, ranged_golbin);
	do_simulation(player_lv1_block, ranged_golbin);
	*/

	do_simulation(player_lv1_stab, steel_knight);
	do_simulation(player_lv1_slash, steel_knight);
	do_simulation(player_lv1_block, steel_knight);

	return 0;
}
