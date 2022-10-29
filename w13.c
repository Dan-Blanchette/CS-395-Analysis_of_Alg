/*********************************************
 * Id: blan5568
 *
 * This program will conduct Russian Peasant
 * Multiplication
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RussianPeasantMult(int n, int m);

int main(int argc, char *argv[])
{
   int nums[argc], i, results;
   char string[] = "------";

   
   if (argc < 2)
   {
      printf("Error: too few args");
      printf("Please enter two integers in the format:  ./a.out 10 13\n");
      exit(0);
   }

   // convert args
   for (i = 0; i < argc; i++)
   {
      nums[ i - 1] = atoi(argv[i]);
   }  

   results = RussianPeasantMult(nums[0], nums[1]);
   printf ("%20s \n", string);
   printf("%20d \n", results);
   return 0;
}

// this function will conduct russian peasant multiplication
int RussianPeasantMult(int n, int m)
{
   if (n == 1)
   {
      printf("   %3d %6d %6d\n",n, m, m);
      return m;
   }
   else if(n % 2 == 0)
   {
      printf("   %3d %6d\n", n, m);
      return (RussianPeasantMult(n/2, m*2));
   }
   else
   {
      printf("   %3d %6d %6d\n", n, m, m);
      return (m + RussianPeasantMult(n/2, m*2));
   }
   //printf("%d ", n);
}