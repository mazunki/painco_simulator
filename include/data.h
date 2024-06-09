
#import "character.h"

typedef struct {
    unsigned long long total_time;
    int battle_count;
    int player_wins;
    int opponent_wins;
} Summary;

Character player = {
    .min_damage = 1,
    .max_damage = 23,
    .health = 100,
    .interval = 4000,
    .accuracy = 1024,
    .evasion = 640,
};

Character steel_knight = {
    .min_damage = 1,
    .max_damage = 32,
    .interval = 2600,
    .health = 150,
    .accuracy = 1216,
    .evasion = 1216,  // melee
};

Character plant = {
    .min_damage = 1,
    .max_damage = 11,
    .interval = 2400,
    .health = 20,
    .accuracy = 170,
    .evasion = 220,  // melee
};

/* vim: set sw=8 ts=8*/

