#ifndef DATA_STARTER_ENEMIES_H
#define DATA_STARTER_ENEMIES_H
#import "character.h"


Character steel_knight = {
        .min_damage = 1,
        .max_damage = 32,
        .interval = 2600,
        .health = 150,
        .accuracy = 1216,
        .evasion = 1216,  // melee
	.style = MELEE,
	.drop_w = 10, .drop_q = 67,
        .name = "Steel Knight",
};

Character golbin = {
        .min_damage = 1,
        .max_damage = 23,
        .interval = 3000,
        .health = 50,
        .accuracy = 640,
        .evasion = 640,  // melee
	.style = MELEE,
	.drop_w = 1, .drop_q = 27,
        .name = "Golbin",
};

Character ranged_golbin = {
        .min_damage = 1,
        .max_damage = 27,
        .interval = 3000,
        .health = 50,
        .accuracy = 640,
        .evasion = 640,  // melee
	.style = RANGED,
	.drop_w = 9, .drop_q = 51,  // (8 normal + 1 oak)/ 51
        .name = "Ranged Golbin",
};

Character chick = {
        .min_damage = 1,
        .max_damage = 10,
        .interval = 4000,
        .health = 30,
        .accuracy = 190,
        .evasion = 190,  // melee
	.style = MELEE,
	.drop_w = 0,
        .name = "Chick",
};

Character plant = {
        .min_damage = 1,
        .max_damage = 11,
        .interval = 2400,
        .health = 20,
        .accuracy = 170,
        .evasion = 220,  // melee
	.style = RANGED,
	.drop_w = 0,
        .name = "Plant",
};

#endif
/* vim: set sw=8 ts=8*/

