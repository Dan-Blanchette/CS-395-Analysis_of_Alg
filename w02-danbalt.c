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
int MinDistance(int A[], int n);
// swap function for selection sort
void swap(int a[], int b[]);
// selection sort algorithm
int partition(int arr[], int l, int h);

void quickSort(int arr[], int l, int h);

// main function
int main(int argc, char *argv[])
{
   int values[argc];
   int i;
   // convert char* argv[] data from a strings to ints
   for (i = 1; i < argc; i++)
   {
      // conversion is working correctly
      values[i - 1] = atoi(argv[i]);
   }
   // Sort data
   quickSort(values, 0, argc);
   // call MinDist and store results in dmin
   int dmin = MinDistance(values, argc);
   printf("%d\n", dmin);

   return 0;
}
// This function will return the minimum distance between the closest
// two elements in an array.
int MinDistance(int A[], int n)
{
   int dmin = INT_MAX;
   int i, j;

   for (i = 0; i < (n - 2); i++)
   {
      for (j = i + 1; j < (n - 1); j++)
      {
         int distance = abs(A[i] - A[j]);
         if (distance < dmin)
         {
            dmin = distance;
         }
      }
   }
   return dmin;
}

// swap function
void swap(int a[], int b[])
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
// partition the array
int partition(int arr[], int l, int h)
{
   int pivot = arr[h]; // pivot
   int i = (l - 1);    // Index of smaller element and indicates the right position of pivot found so far

   for (int j = l; j <= h - 1; j++)
   {
      // If current element is smaller than the pivot
      if (arr[j] < pivot)
      {
         i++; // increment index of smaller element
         swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[i + 1], &arr[h]);
   return (i + 1);
}
// quick sort
void quickSort(int arr[], int l, int h)
{
   if (l < h)
   {
      int index = partition(arr, l, h);

      quickSort(arr, l, index - 1);
      quickSort(arr, index + 1, h);
   }
}