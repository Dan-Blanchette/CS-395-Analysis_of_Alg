/*********************************************
 * Id: blan5568
 *
 * This program uses the Hoare's partition method
 * for the quicksort algorithm
 *********************************************/
#include <stdio.h>
#include <stdlib.h>


int hoaresPartition(int *arr, int low_index, int high_index);

void quickSort(int *arr, int low, int high, int size);

void printSubArrays(int *arr, int begin, int end, const int size);

// Main Driver
int main(int argc, char *argv[])
{
   int num = argc - 1, i;
   int data[num];
   
   for(i = 0; i < num; i++)
   {
      data[i] = atoi(argv[i + 1]);
   }
   quickSort(data, 0, num - 1, num);
   //printSubArrays(data, 0 ,num, num);

   return 0;
}


// FUNCTION DEFINITIONS

// This algorithm selects the first element as a pivot and then initilaizes a left and right index.
// The left index looks for values less than the partition and the right index 
//  looks for values that are greater then swaps the elements.
int hoaresPartition(int *arr, int low_index, int high_index)
{
   int piv = arr[low_index];
   int i = low_index - 1, j = (high_index + 1);

   while (1)
   {
      // Find leftmost element greater than
      // or equal to pivot
      do
      {
         i++;
      }
      while (arr[i] < piv);

      // Find rightmost element less than
      // or equal to the pivot
      do
      {
         j--;
      } 
      while (arr[j] > piv);
      
      if ( i >= j)
      {
         return j;
      }
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp; 
   }
}

// quickSort Function uses the hoares partition to sort an array. 
// NOTE:optimal to use when memory is inline for a system NOT practical for sorting a Database System.
void quickSort(int *arr, int low, int high, int size)
{
   // printSubArrays(arr, low, high, size);
   if(low < high)
   {
      int p_index = hoaresPartition(arr, low, high);

      // Sort each of the sub array elements seperately before
      // partitioning and after.
      quickSort(arr, low, p_index, size);
      quickSort(arr, p_index + 1, high, size);
      printSubArrays(arr, low, high, size);
   }
}

// prints out the partitions and order from the quick sort operation
void printSubArrays(int *arr, int begin, int end, const int size)
{
   int i;
   for(i = 0; i < size; i++)
   {
      if(i == begin)
      {
         printf("[");
      }

      if( i == end)
      {
         printf("%d]  ", arr[i]);
      }
      else
      {
         printf("%d ", arr[i]);
      }
      printf(" ");
   }
   printf("\n");
}