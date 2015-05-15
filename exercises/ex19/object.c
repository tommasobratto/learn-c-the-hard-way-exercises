#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self)
{
    Object *obj = self;

    if(obj) {
        if(obj->description) free(obj->description);
        free(obj);
    }
}
/* This is an template/prototype-like collection of functions
 * related to structs that contain the 'Object' struct, essentially
 * inheriting the functions and variables under Object */ 

void Object_describe(void *self)
{
    Object *obj = self;
    printf("%s.\n", obj->description);
}

int Object_init(void *self)
{
    // do nothing right now
    return 1;
}

void *Object_move(void *self, Direction direction)
{
    printf("You can't go in that direction");
    return NULL;
}

int Object_attack(void *self, int damage)
{
    printf("You can't attack that.\n");
    return 0;
}

void *Object_new(size_t size, Object proto, char *description)
{
    // setup default functions,
    // setting up the prototype functions as the 'Object_' type functions)
    if(!proto.init) proto.init = Object_init;
    if(!proto.describe) proto.describe = Object_describe;
    if(!proto.destroy) proto.destroy = Object_destroy;
    if(!proto.attack) proto.attack = Object_attack;
    if(!proto.move) proto.move = Object_move;

    // change allocation of object pointer,
    // to accomodate for different instances of Object struct
    Object *el = calloc(1, size);
    *el = proto;

    // copy the description
    el->description = strdup(description)

    // initialize it
    if(!el->init(el)) {
        // if it didn't initialize properly
        el->destroy(el);
        return NULL;
    } else {
        // object initialised correctly
        return el;
    }
}
