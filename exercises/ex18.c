/* This is a bubble sorting algorithm program from ex18 of LCTHW.
 * It should be sorting an array of integers in several ways,
 * comparing pairs of adiacent ints in an array and swapping their place
 * if the sorting returns a value greater than zero. 
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// initialise 'exit' function for exception handling
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// creating a 'fake' type for a function pointer
// that compares two integers.
// Functions that are referenced by this pointer define
// the order of the sorting
typedef int (*compare_cb)(int a, int b);

// bubble sort function using pointer to function
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    
    // target is an pointer to array of integers
    int *target = malloc(count * sizeof(int));
    if(!target) die("Memory error");

    /* memcpy(dst, src, n);
     * memcpy copies 'n' bytes from memory 'src' to memory 'dst',
     * essentially creating what I think is a copy of 'target'
     * in the 'numbers' pointer */
    memcpy(target, numbers, count * sizeof(int));

    // for each number do i
    for(i = 0; i < count; i++) {
        // and for each number do j
        for(j = 0; j < count; j++) {
            // if 'compare' returns an int > 0...
            /* 'cmp' is our pointed to function, that means
             * we can use any function we want as long as it's 
             * of the same type and it is an argument of 'bubble_sort' */
            if(cmp(target[j], target[j+1]) > 0) {
                // var temp is equal to second int
                temp = target[j+1];
                // second int is equal to first
                target[j+1] = target[j];
                // first int is equal to temp
                target[j] = temp;
                // result: the second integer gets put in place of the first,
                // the two numbers get swapped in place as long as the numbers given
                // do not follow the order of the sort
            }
        }
    }

    return target;
    // return target int
}

int sorted_order(int a, int b)
{
    return a - b;
    // return first int minus second int
}

int reverse_order(int a, int b)
{
    return b - a;
    // return second int minus first int
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        // return 0 if one of the number's zero
        return 0;
    } else {
        // return the rest of a : b (WAT)
        return a % b;
    }
}

void test_sorting(int *numbers, int count, compare_cb cmp) 
{
    int i = 0;
    // get the sorted numbers and populate the 'sorted' array
    int *sorted = bubble_sort(numbers, count, cmp);

    if(!sorted) die("Failed to sort as requested");

    // for every number print its returned value from the 'sorted' array 
    for(i = 0; i < count; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");

    free(sorted);
}

int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    // count is the number of numbers inserted
    int count = argc - 1;
    int i = 0;

    // 'inputs' is a pointer to the argv array, adding 1 for correct indexing
    char **inputs = argv + 1;

    int *numbers = malloc(count *sizeof(int));
    if(!numbers) die("Memory error.");

    for(i = 0; i < count; i++) {
        // each element of the array 'numbers' is set as one of the arguments
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

    return 0;
}
