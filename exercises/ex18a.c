#include <stdio.h>

int *sorting()
{
    int temp = 0;
    int *target =
    
    for(j = 0; j < count; j++) {
        // if 'compare' returns an int > 0
        if(cmp(target[j], target[j+1]) > 0) {
            // var temp is equal to second int
            temp = target[j+1];
            // second int is equal to first
            target[j+1] = target[j];
            // first int is equal to temp
            target[j] = temp;
            // result: WTF
        }
    }
}

int main(int argc, char *argv[])
{


    return 0;
}
