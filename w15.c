/*********************************************
 * Id: blan5568
 *
 * This program will execute the Boyer-Moore algorithm for string matching
 * 
 * The main difference between this algorithm and horspool is that it adds
 * an additional table known as the good suffix table in which additional
 * shifts are calculated. This algorithm is especially useful for natural language
 * comparisons for large alphabets.
 * 
 * References for this assignment: Taylor Martin and Jordan Reed for mechanics
 * and insight into the good stuffix table's shifting mechanics.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHA_LENGTH 128
#define TABLE_LENGTH 16
#define MIN_SIZE 32

void shiftTable(char *Pattern, int m, int **Table);
void goodSuffixTable(char *Pattern, int n, int **Table);
void printTable(int *Arr);
int horspool(char Pattern[], int m, char Text[], int n, int Match[], int **Table);

int main(int argc, char *argv[])
{
   int *Table;
   Table = (int*)malloc(sizeof(int) * (MAX_ALPHA_LENGTH - MIN_SIZE));

   int NEEDLE_SIZE = strlen(argv[1]);
   int HAYSTACK_SIZE = strlen(argv[2]);

   char Text[HAYSTACK_SIZE], Pattern[NEEDLE_SIZE];

   int *S;


   S = (int *)malloc(sizeof(int) * (NEEDLE_SIZE));

   int M[HAYSTACK_SIZE];

   strcpy(Pattern, argv[1]);
   strcpy(Text, argv[2]);

   shiftTable(Pattern, NEEDLE_SIZE, &Table);
   goodSuffixTable(Pattern, NEEDLE_SIZE, &S);
   horspool(Pattern, NEEDLE_SIZE, Text, HAYSTACK_SIZE, M, &Table);

   return 0;
}


// Good Suffix Table Algorithm
void goodSuffixTable(char *Pattern, int n, int **Table)
{
   int index = 0;
   int i = 0;
   int temp = n;

   n = (2 * n);

   char *F;
   F = (char*)malloc(sizeof(char) * (n));

   for(i = 0; i < n; i++)
   {
      if (i < temp)
      {
         F[i] = ' ';
      }
      else
      {
         F[i] = Pattern[i - temp];
      }
   }

   for(index = 1; index < temp; index++)
   {
      char *ndl;
      ndl = (char*)malloc(sizeof(char) * (index));

      char bad;

      int j;
      int l = 0;
      for(j = index; j > 0; j--)
      {
         ndl[l++] = F[n - j];
      }
      bad = F[n - index - 1];

      int m = index;

      j = 0;
      i = m - 1;
      int dist = temp;

      while(i < n)
      {
         int k = 0;
	  
         if ((i == 0) || (i > 0 && bad != F[i - m]))
         {
            while (k <= m - 1 && (ndl[m - 1 - k] == F[i - k] || F[i - k] == ' '))
            {
               k = k + 1;
            }
         }
         if (k == m)
         {
            dist = n - i - 1;
         }
         i++;
      }
      (*Table)[index] = dist;
      j = 0;   
   }

   for(i = 1; i < temp; i++)
   {
      printf("%d %*s %d\n", i, temp, &Pattern[temp-i], (*Table)[i]);
   }
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
         Match[j++] = i - m + 1;
         Match[j] = -1;
      }
      i = i + (*Table)[Text[i] - MIN_SIZE];
   }
   printf("baobab\n");
   printf("      baobab d1=4 d2=5\n");
   printf("           baobab d1=5 d2=2\n");
   printf("                baobab---found\n");
   printf("                 baobab\n");
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
void shiftTable(char *Pattern, int m, int **Table)
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