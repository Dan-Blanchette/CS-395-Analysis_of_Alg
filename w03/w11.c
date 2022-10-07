/*********************************************
 * Id: blan5568
 *
 * This program will perform selection sort on a
 * data set.
 * Reference:Got Tutoring from James Lasso
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int size);

void printArr(int *arr, int size, int partition);

int main(int argc, char *argv[])
{
   int num = argc - 1, i;
   int intArr[num];
   // convert array data from ascii to integer
   for(i = 0; i < num; i++)
   {
      intArr[i] = atoi(argv[i + 1]);
   }

   // sort the data
   insertionSort(intArr, num);

   return 0;
}

// This function will perform insertion sort.
// The array is partitioned and the element to the left is
// compared with the other elements to the right side of the partition
// once a value is found to be less than the partition, the value is inserted
// and the remaining values are moved to the right of the swapped value.
void insertionSort(int *arr, int size)
{
   int i, j, v;

   for(i = 1; i < size; i++)
   {
      printArr(arr, size, i);
      
      v = arr[i];
      j = i - 1;

      while (j >= 0 && arr[j] > v)
      {
         arr[j + 1] = arr[j];
         j--;
      }
      arr[j + 1] = v;
   }

   int k;

   for(k = 0; k < size; k++)
   {
      printf("%d ", arr[k]);
   }

   printf("| \n");
}

// prints array
void printArr(int *arr, int size, int partition)
{
   int i;
   for(i = 0; i < size; i++)
   {
      if (i == partition)
      {
         printf("| ");
      }
      printf("%d ", arr[i]);
   }
   printf("\n");
}