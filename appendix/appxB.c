// WIP: trying to create an object constructor with the use of malloc and pointers 
// It is currently throwing segfaults

#include <stdio.h>
#include <stdlib.h>

struct TestObject {
    int id;
    const char *name;
};

void exit_func(const char *message)
{
    printf("%s", message);
    exit(1);
}

void Print_object(struct TestObject *obj)
{
    printf("The object id is: %d\n", obj->id);
    printf("The object name is: %s\n", obj->name);
}

struct TestObject *Object_create(int argn, const char *object_name)
{
    int i = 0;
    struct TestObject *obj = malloc(sizeof(struct TestObject));
    if(!obj) exit_func("Memory error");
    
    for(i = 0; i < argn; i++) {

        obj->id = i + 1;
        obj->name = object_name;

        Print_object(obj);
    }

    return obj;
}

void Object_destroy(struct TestObject *obj)
{
    free(obj);
}

int main(int argc, char *argv[])
{
    if(argc < 2) exit_func("Not enough arguments\n");

    int object_num = atoi(argv[1]);
    const char *object_name = argv[2] + '\0';

    struct TestObject *obj = Object_create(object_num, object_name);
    Object_destroy(obj);

    return 0;
}
