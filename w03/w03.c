/*********************************************
 * Id: blan5568
 *
 * This program will calculate 2^n recursively
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
// function that calculates 2^n recursively
int powTwo(int n);

int main(int argc, char *argv[])
{
   int A[argc];
   int i, n;

   for (i =0; i < argc; i++)
   {
      A[i - 1] = atoi(argv[i]);
   }
   n = A[0];
   printf("%d\n", powTwo(n));

   return 0;
}
// function that calculates 2^n recursively
int powTwo(int n)
{
   if (n == 0)
   {
      return 1;
   }
   return powTwo(n-1) + powTwo(n-1);
}