#include <stdio.h>

int main()
{
  int age = 10;
  int height = 72;
  const char swearWord[] = "mofo"; 

  printf("I am %d years old. \n", age);
  printf("I am %d inches tall. \n", height);
  printf("I am a bad %s \n", swearWord);

  return 0;
}
