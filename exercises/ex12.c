#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;

    if(argc == 1) {
        printf("You only have one argument. You suck!\n"); 
    } else if (argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for(i = 0; i < argc; i++) {
            printf("%s \n", argv[i]);
        }
    } else {
        printf("You have too many arguments. You suck. \n");
    }

    return 0;
}
