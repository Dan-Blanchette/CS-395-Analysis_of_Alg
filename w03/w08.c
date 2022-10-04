/*********************************************
 * Id: blan5568
 *
 * This program will conduct string matching
 * by a brute force algorithm
 * Ref:GeeksForGeeks.com
 *********************************************/

void BruteForceStringMatch(char *Text, char *Pattern);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

int main(int argc, char *argv[])
{
   char *text = argv[1];
   char *pattern = argv[2];

   BruteForceStringMatch(pattern, text);  
   return 0;
}

// this function will conduct a string match
// using a brute force method.
void BruteForceStringMatch(char *Text, char *Pattern)
{
   int M = strlen(Pattern);
   int N = strlen(Text);
   int i;
   printf("Matches found at location:");
   for(i = 0; i <= N - M; i++)
   {
      int j;
      for (j = 0; j < M; j++)
      {
         if (Text[i + j] != Pattern[j])
         {
            break;
         }
      }
      if (j == M)
      {
         printf("%d ", i);
      }
   }
   printf("\n");
}