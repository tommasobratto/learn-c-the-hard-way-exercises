#include <stdio.h>

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

    return 0;
}
