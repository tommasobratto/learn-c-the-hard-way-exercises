/* POINTERS */ 

#include <stdio.h>

int main(int argc, char *argv[]) 
{
    // initialise two arrays
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    printf("Ages array size is %d \n", count);
    printf("Size of integer in bytes is %lu \n\n", sizeof(int));

    // use indexing first
    for(i = 0; i < count; i++) {
        printf("%s has %d years alive.\n",
            names[i], ages[i]);
    }

    printf("---\n");

    // setup pointers to the start of the arrays,
    // 'pointer to integer' and 'pointer to 
    // (pointer to char)'
    int *cur_age = ages;
    // it's already a 'string' pointer, 
    // so it needs to be "pointed" again 
    // to get to the array of strings
    char **cur_name = names;

    // use pointers second
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
            /* *(cur_name + i) equals value of 
            pointer value + i, which should be 
            the memory address of a 'current age',
            which in turn is equal to the value of
            names[i] */
            *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // use pointers as arrays third
    for(i = 0; i < count; i++) {
        printf("%s is %d years old again.\n",
            // it's like a differently named array
            cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // use silly pointers fourth,
    // through pointer arithmetic stuff
    for(cur_name = names, cur_age = ages;
        (cur_age - ages) < count;
        cur_name++, cur_age++)
    {
        printf("%s lived %d years so far.\n",
            *cur_name, *cur_age);
    }

    return 0;
}

/* My guess:
A pointer is an arithmetic value that acts as a "tag" 
for a certain piece of data. Whenever you call it, 
you are just referencing the same piece of data everytime.
Basically it is some kind of generic or global variable,
though it could be faster (WARNING: speculation ensues)
because it accesses memory directly instead of going through 
some abstract process of indexing and returning values from 
an abstracted ordered list.

NOTE: if you substitute "tag" for "byte address" and "piece of
data" for "value stored in memory", it kind of makes sense.
Probably, at least. */  

/* What it really is:
Let's start from an array.
In C, calling an array with its name only, for example "ages"
instead of "ages[index]", returns the starting value 
corresponding to "ages[0]", which refers to an integer 
associated to the memory address of that value.
Seen this way, an array becomes just a series of "address" numbers ordered
by an "index" number, each number pointing to a certain value.
We could see the address as a "prefix" (ex: 1241_),
and the index as a "suffix" (ex: ____0), pointing to a certain "place"
in the memory where your value is stored. 
This "address array" can be navigated by adding or subtracting from the suffix number,
for example: "12340 + 1 = 12341" which points to the value at index 1 
of the array referenced by the prefix number.
In the end, C thinks of computer memory as a huge array of bytes,
each potentially representing some kind of value. Different types of
variables take different quantities of bytes to allocate a value, 
for example "int = 4", and arrays are just ordered groups of allocated values in these bytes. */ 


/* TODO
 ============

Try to make cur_age point at names. You'll need to use a C cast to force it, so go look that up and try to figure it out.
In the final for-loop try getting the math wrong in weird ways.
Try rewriting the loops so they start at the end of the arrays and go to the beginning. This is harder than it looks.
Rewrite all the array usage in this program so that it's pointers.
Rewrite all the pointer usage so they're arrays.
Process command line arguments using just pointers similar to how you did names in this one.
Play with combinations of getting the value of and the address of things.
Add another for-loop at the end that prints out the addresses these pointers are using. You'll need the %p format for printf.
Rewrite this program to use a function for each of the ways you're printing out things. Try to pass pointers to these functions so they work on the data. Remember you can declare a function to accept a pointer, but just use it like an array.
Change the for-loops to while-loops and see what works better for which kind of pointer usage. */
