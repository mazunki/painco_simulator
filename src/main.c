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
}

int main() {
    srand(time(NULL));
    setlocale(LC_NUMERIC, "");

    Summary s = {0};
    simulate_battles(&s, player, steel_knight, NUMBER_OF_SIMULATIONS);

    print_summary(s);
    
    return 0;
}
