/*********************************************
 * Id: blan5568
 * Dan Blanchette
 * 
 * This calcuates the permuations in a string
 *********************************************/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *x, char *y);
void permute(char *a, int left, int right);

// main
int main(int argc, char *argv[])   
{
  
   int n;
   n = atoi(argv[1]);

   if(n == 5)
   {
      char str[] = "12345";
      int n = strlen(str);
      permute(str, 0, n-1);
   }
   else if (n == 4)
   {
      char str[] = "1234";
      int n = strlen(str);
      permute(str, 0, n-1);
   }
   else if (n == 3)
   {
      char str[] = "123";
      int n = strlen(str);
      permute(str, 0, n-1);
   }
   else if (n == 2)
   {
      char str[] = "1234";
      int n = strlen(str);
      permute(str, 0, n-1);
   }

   return 0;
}
//swap function
void swap(char *x, char *y)
{
   char temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

//recurse through permutations and calculate
void permute(char *a, int left, int right)
{
   int i; 
   if (left == right)   
   {
      printf("%s\n", a);
   }
   else   
   {
      for (i = left; i <= right; i++)   
      {
         swap((a + left), (a + i));
         permute(a, left + 1, right);
         swap((a + left), (a + i));
      }
   }
}