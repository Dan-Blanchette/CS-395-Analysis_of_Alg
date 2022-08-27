/*********************************************
 * Id: blan5568
 *
 * This program will find the minimum distance between the closest
 * two elements in an array
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// This function will return the minimum distance between the closest
// two elements in an array.*/
int MinDistance(int *A, int n);

// This function is the swap portion of the quick sort algorithm
void swap(int *a, int *b);

// This function partitions the array relative to where the pivot is
// in the quick sort process
int partition(int *array, int low, int high);

// the quick sort function sorts an array based on the values above and below
// the pivot value and triggers a swap based on the position the data is in
void quicksort(int *array, int low, int high);

// The main function
int main(int argc, char **argv)
{
   int values[argc];
   int n = 0;
   for(int i = 1; i < argc; i++)
   {
      // conversion is working correctly
      values[i] = atoi(argv[i]);
      n = ((sizeof(values) / sizeof(values[0])) - 1);
      quicksort(values, 0, n - 1);
      int dmin = MinDistance(values, n);
      printf("%d\n", dmin);
   }
   return 0;
}

/* This function will return the minimum distance between the closest
*  two elements in an array.*/
int MinDistance(int *A, int n)
{
   int dmin = INT_MAX;
   int i, j;

   for(i = 0; i < n; i++)
   {
      for(j = i + 1; j < n; j++)
      {
         if(abs(A[i]- A[j]) < dmin)
         {
            dmin = abs(A[i] - A[j]);
         }
      }
   }
   return dmin;
}

// This function is the array element value swap portion of 
// the quick sort algorithm
void swap(int *a, int *b)
{
   int t = *a;
   *a = *b;
   *b = t;
}

// This function partitions the array relative to where the pivot is
// in the quick sort process
int partition(int *array, int low, int high)
{
   // find the rightmost element of the array
   int pivot = array[high];

   // points to the greater element 
   int i = (low - 1), j;

   // check each element of the array
   // and compare the contents with the pivot
   for(j = low; j < high; j++)
   {
      if(array[j] <= pivot)
      {
         i++;
         swap(&array[i], &array[j]);
      }
   }
   // return the partion point
   return (i +1);
}

// the quick sort function sorts an array based on the values above and below
// the pivot value and triggers a swap based on the position the data is in
void quicksort(int *array, int low, int high)
{
   if(low < high)
   {
      int piv_el = partition(array, low, high);
      // recursive call to the left of the pivot
      quicksort(array, low, piv_el - 1);
      //recursive call to the right of the pivot
      quicksort(array, piv_el + 1, high);

   }
}