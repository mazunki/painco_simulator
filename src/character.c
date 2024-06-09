
#include <stdlib.h>
#include <stdio.h>

#include "character.h"

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

void print_target(Character c) {
    printf("%s with dmg: [%d, %d] @ hit chance: %.3f%% every %d ms\n", c.name, c.min_damage, c.max_damage, 100.00*c.hit_chance, c.interval);
}

/* vim: set sw=4 ts=8 expandtab*/

