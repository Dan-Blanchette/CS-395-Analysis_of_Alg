/*********************************************
 * Id: blan5568
 *
 * This program uses the Hoare's partition method
 * for the quicksort algorithm
 * CREDIT: Help from Taylor Martin for Print Statement Formatting
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

int hoaresPartition(int *arr, int low_index, int high_index);

void quickSort(int *arr, int low, int high, int size);

void swap(int *arr, int i, int j);

void printSubArrays(int *arr, int begin, int end, const int size);

// Main Driver
int main(int argc, char *argv[])
{
   // arg check
   if(argc < 2)
   {
      printf("Error");
      return 1;
   }

   int num = argc - 1, i;
   int data[num];

   for (i = 0; i < num; i++)
   {
      data[i] = atoi(argv[i + 1]);
      printf("%d ", data[i]);
   }
   printf("\n");
   quickSort(data, 0, num - 1, num);
   printSubArrays(data, 0 ,num - 1, num);

   return 0;
}

// FUNCTION DEFINITIONS

// This algorithm selects the first element as a pivot and then initilaizes a left and right index.
// The left index looks for values less than the partition and the right index
//  looks for values that are greater then swaps the elements.
int hoaresPartition(int *arr, int low_index, int high_index)
{
   int piv = arr[low_index];
   int i = low_index, j = (high_index + 1);

   while (i < j)
   {
      while(arr[++i] < piv){}
      while(arr[--j] > piv){}
      // Swap elements
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
   }
   // swap
   int temp1 = arr[i];
   arr[i] = arr[j];
   arr[j] = temp1;

   // Undo last swap
   int temp2 = arr[low_index];
   arr[low_index] = arr[j];
   arr[j] = temp2;
   

   return j;
}

// quickSort Function uses the hoares partition to sort an array.
// NOTE:optimal to use when memory is inline for a system NOT practical for sorting a Database System.
void quickSort(int *arr, int low, int high, int size)
{
   // printSubArrays(arr, low, high, size);
   if (low < high)
   {
      int p_index = hoaresPartition(arr, low, high);

      // Sort each of the sub array elements seperately before
      // partitioning and after.
      quickSort(arr, low, p_index - 1, size);
      quickSort(arr, p_index + 1, high, size);
      printSubArrays(arr, low, high, size);
   }
}

// prints out the partitions and order from the quick sort operation
void printSubArrays(int *arr, int begin, int end, const int size)
{
   int i;
   for (i = 0; i < size; ++i)
   {
      if (i == begin)
      {
         printf("[");
      }

      if (i == end)
      {
         printf("%d] ", arr[i]);
      }
      else
      {
         printf("%d", arr[i]);
      }
      printf(" "); 
   }
   printf("\n");
}

// swap helper funciton swaps array elements
void swap(int *arr, int i, int j)
{
   int temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}