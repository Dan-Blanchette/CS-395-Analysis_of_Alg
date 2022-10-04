/*********************************************
 * Id: blan5568
 *
 * This program will solve the Towers of Hanoi
 * Puzzle
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char from_post, char to_post, char neu_post);

int main(int argc, char *argv[])
{
   int disks, i;
   int convArgs[argc];
   // convert the commandline arguments from ascii to int
   for(i = 0; i < argc; i++)
   {
      convArgs[i-1] = atoi(argv[i]);
   }
   disks = convArgs[0];
   towerOfHanoi(disks, 'A', 'C', 'B');

   return 0;
}
// This program will complete the tower of hanoi puzzle
void towerOfHanoi(int n, char from_post, char to_post, char neu_post)
{
   if(n == 1)
   {
      printf("Move %c to %c\n", from_post, to_post);
      return;
   }
   towerOfHanoi(n-1, from_post, neu_post, to_post);
   printf("Move %c to %c\n", from_post, to_post);
   towerOfHanoi(n-1, neu_post, to_post, from_post);
}
