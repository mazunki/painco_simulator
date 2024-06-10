#ifndef DATA_PLAYER_H
#define DATA_PLAYER_H
#import "character.h"

Character player_lv1_stab = {
        .min_damage = 1,
        .max_damage = 23,
        .health = 100,
        .interval = 4000,
        .accuracy = 1024,
        .evasion = 640,
        .name = "Player (stab, lv1)",
};

Character player_lv1_slash = {
        .min_damage = 1,
        .max_damage = 29,
        .health = 100,
        .interval = 4000,
        .accuracy = 640,
        .evasion = 640,
        .name = "Player (slash, lv1)",
};

Character player_lv1_block = {
        .min_damage = 1,
        .max_damage = 23,
        .health = 100,
        .interval = 4000,
        .accuracy = 640,
        .evasion = 1024,  // melee
        .name = "Player (block, lv1)",
};

Character player_bbaxe_stab = {
        .min_damage = 1,
        .max_damage = 23,
        .health = 100,
        .interval = 4000,
        .accuracy = 1024,
        .evasion = 640,
        .name = "Player (stab, lv1)",
};

Character player_bbaxe_slash = {
        .min_damage = 1,
        .max_damage = 29,
        .health = 100,
        .interval = 4000,
        .accuracy = 640,
        .evasion = 640,
        .name = "Player (slash, lv1)",
};

Character player_bbaxe_block = {
        .min_damage = 1,
        .max_damage = 23,
        .health = 100,
        .interval = 4000,
        .accuracy = 640,
        .evasion = 1024,  // melee
        .name = "Player (block, lv1)",
};

#endif

/* vim: set sw=8 ts=8*/

