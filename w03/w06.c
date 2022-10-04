/*********************************************
 * Id: blan5568
 *
 * This program will solve the Towers of Hanoi
 * Puzzle
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// this function will solve the resticted tower of hanoi problem
void towerOfHanoi(int n, char from_post, char to_post, char neu_post);

int main(int argc, char *argv[])
{
   int disks, i;
   int convArgs[argc];
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
   // move n -1 disks from first to last.
   towerOfHanoi(n - 1, first, middle, last);
   printf("Move %c to %c\n", first, middle);

   // move n - 1 disks from last to first
   towerOfHanoi(n - 1, last, middle, first);
   printf("Move %c to %c\n", middle, last);

   // move n -1 disks from first to last
   towerOfHanoi(n - 1, first, middle, last);
}