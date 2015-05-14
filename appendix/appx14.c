#include <stdio.h>

// figuring out what pointers do
int main()
{
    // initialise string array
    char *str[] = {
        "Lorem"
    };

    // initialise pointer to array/string
    char **cur_str = str;

    // return pointer value
    printf("the value is %s\n", *(cur_str));

    return 0;
}
