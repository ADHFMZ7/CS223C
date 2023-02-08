#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


// defines true and false constants
#define FALSE 0
#define TRUE 1

// optimizations found on 
int isPrime(long n) {

   if(n == 1) return FALSE;
   if(n <= 3) return TRUE;
   

   for(int i = 2; pow(i, 2) <= n; i += 6)
   {
      if(!(n % 2) || !(n % 3)) return FALSE;
      if(!(n % i) || !(n % (i + 2))) return 0;
   }
   return TRUE;
}


void printFactors(long n)
{
   printf("Factors of %ld: ", n);
   for (long i = 0; i <= n; i++)
   {
      if (!(n % i)) printf("%ld ", i);
   }
   printf("\n");
}


int main()
{

   printf("Prime Checker by Ahmad Aldasouqi \n");

   char buffer[40];
   long number;
   
   do {
      printf("Input an integer: ");
      assert(fgets(buffer, 39, stdin) != NULL);
      number = atol(buffer);
   } while (!number);
   
    
   if (isPrime(number)) printf("%ld is prime\n", number);
   else printFactors(number);
}
