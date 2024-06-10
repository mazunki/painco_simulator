#ifndef CHARACTER_H
#define CHARACTER_H
#include <stdbool.h>

typedef enum {
	MELEE,
	RANGED,
	MAGIC
} AttackStyle;

typedef struct {
        int min_damage;
        int max_damage;
        int accuracy;
        int evasion;
        int interval;
        int health;
        double hit_chance;
	AttackStyle style;
	int drop_w, drop_q;
	int successful_hits;
        const char *name;
} Character;

int random_damage(int min, int max);
bool hit_target(int accuracy, int evasion);
double chance_to_hit(int accuracy, int evasion);

#endif
/* vim: set sw=8 ts=8*/

