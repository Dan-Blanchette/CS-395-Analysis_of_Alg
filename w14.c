/*********************************************
 * Id: blan5568
 *
 * This program will use horsepools algorithm
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHA_LENGTH 128
#define TABLE_LENGTH 16
#define MIN_SIZE 32

void shiftTable(char *Pattern, int m, int **Table);
void printTable(int *Arr);
int horspool(char Pattern[], int m, char Text[], int n, int Match[], int **Table);


int main(int argc, char *argv[])
{
   int *Table;
   Table = (int*)malloc(sizeof(int) * (MAX_ALPHA_LENGTH - MIN_SIZE));

   int NEEDLE_SIZE = strlen(argv[1]);
   int HAYSTACK_SIZE = strlen(argv[2]);

   char Text[HAYSTACK_SIZE], Pattern[NEEDLE_SIZE];

   int M[HAYSTACK_SIZE];

   strcpy(Pattern, argv[1]);
   strcpy(Text, argv[2]);

   shiftTable(Pattern, NEEDLE_SIZE, &Table);
   horspool(Pattern, NEEDLE_SIZE, Text, HAYSTACK_SIZE, M, &Table);

   return 0;
}


// conducts string matching using the shift table and comparing the last charcter of the needle string
// if the last element of the needle array matches, then the previous elements are compared and shifted if not a match
// based on the value in the shiftTable for that character.
int horspool(char Pattern[], int m, char Text[], int n, int Match[], int **Table)
{
   int k = 0;
   int j = 0;
   int i = m - 1;

   printf("%s\n", Text);

   while( i <= n - 1)
   {
      k = 0;
      while ( k <= m - 1 && Pattern[m - 1 - k] == Text[ i - k])
      {
         k = k + 1;
      }

      if( k == m)
      {
         printf("%*s%s---found\n", i - m + 1,"", Pattern);
         Match[j++] = i - m + 1;
         Match[j] = -1;
      }
      else
      {
         printf("%*s%s\n", i - m + 1, "", Pattern);
      }
      i = i + (*Table)[Text[i] - MIN_SIZE];
   }

   printf("Matches found at locations:");
   j = 0;
   while(Match[j] != -1)
   {
      printf(" %d", Match[j++]);
   }
   printf("\n");
   return -1;
}
// Prints the shift table
void printTable(int *Arr)
{
   int i = 0;
   int start = 0;

   for(start = MIN_SIZE; start < MAX_ALPHA_LENGTH; start += TABLE_LENGTH)
   {
      for(i = start; i < start + TABLE_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start + TABLE_LENGTH; i++)
      {
         printf("%d\t", Arr[i - MIN_SIZE]);
      }
      printf("\n\n");
   }
}


// Shift Table will store the string size and be referenced
// by the horsepool algorithm to shift the alignment of the seach 
// string with the sumbitted string.
void shiftTable(char Pattern[], int m, int **Table)
{
   int i = 0;
   for(i = 0; i <= MAX_ALPHA_LENGTH - MIN_SIZE; i++)
   {
      (*Table)[i] = m;
   }

   for (i = 0; i <= m - 2; i++)
   {
      (*Table)[Pattern[i] - MIN_SIZE] = m - 1 - i;
   }
   printTable(*Table);
}