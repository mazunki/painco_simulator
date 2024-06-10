
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "character.h"
#include "simulation.h"

bool hit_target(int accuracy, int evasion) {
	int hit_chance;
	if (accuracy < evasion) {
		hit_chance = accuracy * 16384 / (2 * evasion);
} else {
		hit_chance = 16384 - (evasion * 16384 / (2 * accuracy));
	}
	return (rand() % 16384) < hit_chance;
}
bool roll_item(int w, int q) {
	if (w == 0) return false;
	return rand() % q < w;
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

void simulate_battles(Summary *s, Character player, Character enemy, int n) {
	s->battle_count += n;

	player.hit_chance = chance_to_hit(player.accuracy, enemy.evasion);
	enemy.hit_chance = chance_to_hit(enemy.accuracy, player.evasion);
	printf("Running %'d simulations.\n", n);
	print_target(player);
	print_target(enemy);
	printf("\n");

	while (n--) {
		Character _player;
		Character _enemy;

		memcpy(&_player, &player, sizeof(Character));
		memcpy(&_enemy, &enemy, sizeof(Character));

		s->total_time += simulate_battle(&_player, &_enemy);
		if (_player.health > 0) {
			s->player_wins++;
			if (roll_item(enemy.drop_w, enemy.drop_q)) {
				s->drops++;
			}
		} else {
			s->opponent_wins++;
		}
	}
}

/* vim: set sw=4 ts=4 expandtab*/

