#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int i = 0;

    // go through each string in argv
    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // initialise array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    
    int num_states = 4;

    for (i = 0; i < num_states; i++) {
        if (states[i] == states[1]) {
            printf("state %d: %s\n", i, states[i]);
            break;
        }
    }

    return 0;
}
