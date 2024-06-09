#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "character.h"
#include "data.h"

int random_damage(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double chance_to_hit(int accuracy, int evasion) {
    if (accuracy < evasion) {
        return (double) accuracy / (double) (2*evasion);
    } else {
        return 1.0 - ((double) evasion / (double) (2*accuracy));
    }
}

bool hit_target(int accuracy, int evasion) {
    int hit_chance;
    if (accuracy < evasion) {
        hit_chance = accuracy * 1024 / (2 * evasion);
    } else {
        hit_chance = 1024 - (evasion * 1024 / (2 * accuracy));
    }
    return (rand() % 1024) < hit_chance;
}

long simulate_battle(Character *player, Character *opponent) {
    long time = 0;
    long time_to_player;
    long time_to_opponent;

    while (player->health > 0 && opponent->health > 0) {
        if ((time % player->interval) == 0) {
            if (hit_target(player->accuracy, opponent->evasion)) {
                opponent->health -= random_damage(player->min_damage, player->max_damage);
            }
        }

        if ((time % opponent->interval) == 0) {
            if (hit_target(opponent->accuracy, player->evasion)) {
                player->health -= random_damage(opponent->min_damage, opponent->max_damage);
            }
        }

        time_to_player = player->interval - time % player->interval;
        time_to_opponent = opponent->interval - time % opponent->interval;

        time += (time_to_player < time_to_opponent) ? time_to_player : time_to_opponent;
    }
    return time;
}

void print_target(const char *name, Character c) {
    printf("%s with dmg: [%d, %d] @ hit chance: %.3f%% every %d ms\n", name, c.min_damage, c.max_damage, 100.00*c.hit_chance, c.interval);
}

void simulate_battles(Summary *s, int n) {
    s->battle_count += n;

    Character enemy = steel_knight;

    player.hit_chance = chance_to_hit(player.accuracy, enemy.evasion);
    enemy.hit_chance = chance_to_hit(enemy.accuracy, player.evasion);
    printf("Running %d simulations.\n", n);
    print_target("Player", player);
    print_target("Enemy", enemy);
    printf("\n");

    while (n--) {
        Character _player;
        Character _enemy;

        memcpy(&_player, &player, sizeof(Character));
        memcpy(&_enemy, &enemy, sizeof(Character));

        s->total_time += simulate_battle(&_player, &_enemy);
        if (_player.health > 0) {
            s->player_wins++;
        } else {
            s->opponent_wins++;
        }
    }
}

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
    
    
    int num_simulations = 100*1000*1000;
    // printf("Enter the number of simulations: ");
    // scanf("%d", &num_simulations);

    Summary s = {0};
    simulate_battles(&s, num_simulations);

    print_summary(s);
    
    return 0;
}
