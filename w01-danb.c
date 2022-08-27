/*********************************************
* Id: Dan Blanchette
*
* Compile: gcc -Wall
* Run: ./a.out input.txt
*
* This program will find the minimum distance between the closest
* two elements in an array
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* This function will return the minimum distance between the closest
*  two elements in an array.*/
int MinDistance(int A[], int n);

int main(int argc, char **argv)
{
   int values[argc];
   int n = 0;
   for(int i = 1; i < argc; i++)
   {
      // conversion is working correctly
      values[i] = atoi(argv[i]);
      n = ((sizeof(values) / sizeof(values[0])) - 1);
      int dmin = MinDistance(values, n);
      printf("%d\n", dmin);
   }
   return 0;
}

/* This function will return the minimum distance between the closest
*  two elements in an array.*/
int MinDistance(int A[], int n)
{
   int dmin = INT_MAX;
   int i, j;

   for(i = 0; i < n; i++)
   {
      for(j = 0; j < n; j++)
      {
         if((i != j) && (abs(A[i]- A[j]) < dmin))
         {
            dmin = abs(A[i] - A[j]);
         }
      }
   }
   return dmin;
}