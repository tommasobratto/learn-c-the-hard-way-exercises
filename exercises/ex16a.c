#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// trying the "stack allocation" way of doing things in "Extra Creditx"
struct Person Person_create(char *name, int age, int height, int weight)
{
    struct Person who;

    who.name = name;
    who.age = age;
    who.height = height;
    who.weight = weight;

    return who;
}

void Person_print(struct Person who)
{
    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n\n", who.weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person joe = Person_create(
        "Joe Alex", 32, 64, 140);

    struct Person frank = Person_create(
        "Frank Blank", 20, 72, 180);

    Person_print(joe);
    Person_print(frank);

    // make everyone age 20 years and print them again
    printf("after 20 years in development\n\n");
    joe.age += 20;
    joe.height -= 2;
    joe.weight += 40; 
    Person_print(joe);

    frank.age += 20;
    frank.weight += 20;
    Person_print(frank);

    return 0;
}
