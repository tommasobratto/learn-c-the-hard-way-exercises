// Implementing the game

#ifndef _ex19_h
#define _ex19_h

#include "object.h"

// declaring our Monster object
struct Monster {
    Object proto;
    int hit_points;
};

// declaring it as a template 'type'
typedef struct Monster Monster;

// declaring the functions the Monster object can use
int Monster_attack(void *self, int damage);
int Monster_init(void *self);

// defining our Room object
struct Room {
    Object proto;

    // it contains a Monster object
    Monster *bad_guy;

    // and several locations
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
};

typedef struct Room Room;

struct Map {
    // it contains the Room object
    // and a starting point
    Object proto;
    struct Room *start;
    struct Room *location;
};

// declaring a template 'type' for a map
typedef struct Map Map;

// declaring functions to be used by the Map object
void *Map_move(void *self, Direction direction);
int Map_attack(void *self, int damage);
int Map_init(void *self);

#endif
