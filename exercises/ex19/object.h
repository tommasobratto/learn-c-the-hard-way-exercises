/* Exercise 19: Building an object system in C. 
 * This is a small game program made to try OO-like 
 * programming in C and learn how to use the C Pre-Processor. */ 

/* The object system of this exercise is based on the 
 * Javascript prototype system, since class-based systems
 * are difficult to implement in C (at least this is what LCTHW says). */

/* The CPP (abbreviation for C Pre-Processor) works to actually create
 * and remove code, and even execute logic. */

// 'ifndef': if argument not defined, execute code below
#ifndef _object_h
#define _object_h

typedef enum {
    NORTH, SOUTH, EAST, WEST
} Direction;

// defining our Object template/struct, and the functions available to it
typedef struct {
    char *description;
    // pointers to functions that will use the functions declared below
    int (*init)(void *self);
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

// macro that executes automatically the code on the right, with T and N as arguments.
// T##Proto means "Concat Proto at the end of T".
// All of this feels really confusing at the moment.
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
// Syntactic sugar to write obj without specifying the prototype the object comes from.
#define _(N) proto.N

#endif
