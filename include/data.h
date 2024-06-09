#ifndef DATA_H
#define DATA_H
#import "character.h"

#ifndef NUMBER_OF_SIMULATIONS
#define NUMBER_OF_SIMULATIONS 100*1000*1000
#endif

Character player = {
        .min_damage = 1,
        .max_damage = 23,
        .health = 100,
        .interval = 4000,
        .accuracy = 1024,
        .evasion = 640,
        .name = "Player",
};

Character steel_knight = {
        .min_damage = 1,
        .max_damage = 32,
        .interval = 2600,
        .health = 150,
        .accuracy = 1216,
        .evasion = 1216,  // melee
        .name = "Steel Knight",
};

Character plant = {
        .min_damage = 1,
        .max_damage = 11,
        .interval = 2400,
        .health = 20,
        .accuracy = 170,
        .evasion = 220,  // melee
        .name = "Plant",
};

#endif // DATA_H

/* vim: set sw=8 ts=8*/

