#include <stdio.h>

int main(int argc, char *argv[])
{
    // ERROR message only if using one argument per execution

    // if(argc != 2) {
    //     printf("ERROR: You need one argument.\n");
    //     // abort program message with the next line
    //     return 1;
    // }

    int i = 0;
    
    for(i = 0; i < argc; i++) {

        /* This "for loop" stuff is weird, better leave it for another time...
        I need to find a way to add more than one argument and check 
        for each argument and each letter of the argument checked... WTF */

        char word[5] = { *argv[i] };
        char letter;
        int j;

        for(j = 0;  letter = word[i][j], word[i][j] != '\0'; j++) {
            // char letter = argv[1][i]; *old "regular" style*

            switch(letter) {
                case 'a':
                case 'A':
                    printf("%d: 'A'\n", i);
                    break;

                case 'e':
                case 'E':
                    printf("%d: 'E'\n", i);
                    break;

                case 'i':
                case 'I':
                    printf("%d: 'I'\n", i);
                    break;

                case 'o':
                case 'O':
                    printf("%d: 'O'\n", i);
                    break;

                case 'y':
                case 'Y':
                    if(j < 2) {
                        // sometimes Y
                        printf("%d: 'Y'\n", i);
                    }
                break;

                default:
                    printf("%d: %c is not a vowel\n", i, letter);
            }
        }
    }

    return 0;
}
