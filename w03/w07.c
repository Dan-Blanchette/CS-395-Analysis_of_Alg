/*********************************************
 * Id: blan5568
 *
 * This program will solve the Cyclic Towers
 * of Hanoi Puzzle
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// this function will solve the resticted tower of hanoi problem
void towerOfHanoi(int n, char from_post, char to_post, char neu_post);

int main(int argc, char *argv[])
{
   int disks, i;
   int convArgs[argc];
   exception check for insufficient args passed
   if(argc <= 1)
   {
      printf("Error insufficient arguments entered\n FORMAT: ./a.out {INT}\n");
      printf("The Program will now exit\n");
      exit(1);
   }
   // convert the commandline arguments from ascii to int
   for (i = 0; i < argc; i++)
   {
      convArgs[i - 1] = atoi(argv[i]);
   }
   disks = convArgs[0];
   // for this implementation the rods are in order
   towerOfHanoi(disks, 'A', 'B', 'C');

   return 0;
}
// This program will complete the tower of hanoi puzzle
void towerOfHanoi(int n, char first, char middle, char last)
{
   if (n == 1)
   {
      printf("Move %c to %c\n", first, middle);
      printf("Move %c to %c\n", middle, last);
      return;
   }
   else if (n == 2)
   {
      printf("Move %c to %c\n", first, middle);
      printf("Move %c to %c\n", middle, last);
      printf("Move %c to %c\n", first, middle);
      printf("Move %c to %c\n", last, first);
      printf("Move %c to %c\n", middle, last);
      printf("Move %c to %c\n", first, middle);
      printf("Move %c to %c\n", middle, last);
   }
   else
   {
      // move n -1 disks from first to last.
      towerOfHanoi(n - 1, first, middle, last);
      printf("Move %c to %c\n", first, middle);

      // move n - 2 disks from last to first
      towerOfHanoi(n - 2, last, first, middle);
      printf("Move %c to %c\n", last, first);

      // move n - 2 disks from middle to last
      towerOfHanoi(n - 2, middle, last, first);
      printf("Move %c to %c\n", middle, last);

      // move n -1 disks from first to last
      towerOfHanoi(n - 1, first, middle, last);
   }
}
