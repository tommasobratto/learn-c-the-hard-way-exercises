// Printing info about variable/pointer memory addresses and bytesizes
#include <stdio.h>
#include <stdlib.h>

int sum(int number, int number2)
{
    return number + number2;
}

struct Object {
    int number;
    int number2;
    int sum;
};

struct Object *Object_new(int number, int number2)
{   
    struct Object *obj = malloc(sizeof(struct Object));

    obj->number = number;
    obj->number2 = number2;

    return obj;
}

int main(int argc, char *argv[])
{
    printf("\n");

    // declare a variable
    int a = 1;
    char b = 'b';

    // print the variable values
    printf("Value of 'a': %d\n", a);
    printf("Value of 'b': %c\n", b);

    // get the memory address of the variable
    printf("Memory address of 'a': %p\n", &a);
    printf("Memory address of 'b': %p\n", &b);

    // get the bytesize of the variable
    printf("Bytesize of 'a': %lu\n", sizeof(a));
    printf("Bytesize of 'b': %lu\n", sizeof(b));

    printf("---\n");

    // declare two pointers and do the same thing
    int *c = &a;
    char *d = &b;

    printf("Value of '*c': %d\n", *c);
    printf("Value of '*d': %c\n", *d);

    printf("Memory address of '*c': %p\n", &c);
    printf("Memory address of '*d': %p\n", &d);

    printf("Bytesize of '*c': %lu\n", sizeof(*c));
    printf("Bytesize of '*d': %lu\n", sizeof(*d));

    // declaring and accessing an attribute of a struct
    // with an initialiser function
    struct Object *obj = Object_new(2, 2);

    obj->sum = sum(obj->number, obj->number2);

    printf("\nThe sum of the numbers stored in 'obj' is %d\n\n", obj->sum);

    free(obj);
    return 0;
}
