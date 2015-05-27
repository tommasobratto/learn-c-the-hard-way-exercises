/* Exercise 19: Building an object system in C. 
 * This is a small game program made to try OO-like 
 * programming in C and learn how to use the C Pre-Processor. */ 

/* The object system of this exercise is based on the 
 * Javascript prototype system, since class-based systems
 * are difficult to implement in C (at least this is what LCTHW says). */

/* The CPP (abbreviation for C Pre-Processor) works to create
 * and remove code, and even execute logic. */


// The "object.h" file is dedicated to declaring the object struct with
// the functions that we need

// 'ifndef': if argument not defined, execute code below
#ifndef _object_h
#define _object_h

// 'enum' type means list of keywords
typedef enum {
    NORTH, SOUTH, EAST, WEST
} Direction;

// defining our Object template/struct, and the functions available to it
typedef struct {
    char *description;
    /* pointers to functions that will use the functions declared below,
     * can accept different naming like 'Room_init' or 'Monster_init',
     * as long as it maintains the same declaration syntax */ 
    int (*init)(void *self);
    /* 'void *self' is used to call the object in itself (kinda like 'this' for Javascript).
     * It is a pointer to the object struct that calls a specific function
     * or member variable. */
    void (*describe)(void *self);
    void (*destroy)(void *self);
    void *(*move)(void *self, Direction direction);
    int (*attack)(void *self, int damage);
} Object;

// declaring the functions used by the struct Object
int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

/* macro that executes automatically the code on the right, 
 * with T (title) and N (description) as arguments.
 * What it does is just calling *Object_new automatically, more or less.
 * T##Proto means "Concat Proto at the end of T"... 
 * like, if I had an object called "Room" then it would call
 * the prototype of it "RoomProto" */ 
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
// Syntactic sugar to write obj without specifying the prototype the object comes from.
// for example: 'obj->proto.room' would become 'obj->_(room)'
#define _(N) proto.N

#endif
