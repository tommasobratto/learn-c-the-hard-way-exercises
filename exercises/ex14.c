#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* forward declaration, declaring functions 
before actually defining them, for example:
print_letters is used by print_arguments,
which is the first function to be called when
"main" runs. 
print_letters then calls can_print_it, thus requiring
the "used" functions to be declared before or incur
into a undefined function error or similar */
// Former function declaration in the exercise.
// int can_print_it(char ch);
void print_letters(char arg[], int str_len);

// Research 'check for string length C',
// to complete the exercise

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; i++) {
        int str_len = strlen(argv[i]);
        print_letters(argv[i], str_len);
    }
}

void print_letters(char arg[], int str_len)
{
    int i = 0;

    for(i = 0; arg[i] != str_len; i++) {
        char ch = arg[i];

        if(isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch );
        }
    }
    printf("\n");
}

/* Former function in the exercise.
    int can_print_it(char ch)
    {
        depends on 'ctype' library, checks if ASCII
        character value is equal to alpha char or 
        blank space. If it's not true for either 
        of those values, it just skips the 'character 
        = value' printing
        return isalpha(ch) || isblank(ch);
    } */

int main(int argc, char *argv[]) 
{
    print_arguments(argc, argv);
    return 0;
}
