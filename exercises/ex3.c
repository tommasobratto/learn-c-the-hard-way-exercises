#include <stdio.h>
#include <assert.h>

int main() 
{
  int age = 10;
  int height = 72;
  const char swearWord[] = "mofo"; 

  // assert(swearWord[0] == 'm');
  // assert(swearWord[4] == '\0');

  printf("I am %d years old. \n", age);
  printf("I am %d inches tall. \n", height);
  printf("I am a bad %s \n", swearWord);

  return 0;
}
