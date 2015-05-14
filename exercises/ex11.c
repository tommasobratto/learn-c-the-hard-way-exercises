#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 1;
    while (i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // initialise an array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;

    i = 0;

    while (i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    i = 1;
    num_states = 3;

    while (i < argc) {
        states[num_states + i] = argv[i];
        printf("index of arg is %d, content is %s\n", num_states + i, states[num_states + i]);
        i++;
    } 
    // this returns "abort trap: 6", probably because of non-allocated memory for new array size

    return 0;
}
