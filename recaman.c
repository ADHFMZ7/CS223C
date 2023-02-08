// Ahmad Aldasouqi
// CS 223C
// Recaman Sequence

// TODO: Finish implementation of recursive algorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

int contains(int *array, int len, int contain)
{
   for (int idx = 0; idx < len; idx++)
   {
      if (array[idx] == contain)
      {
         return 1;
      }
   }
   return 0;
}

int recaman_iterative(int n)
{

   int array[n + 1];
   array[0] = 0;
   int prev;

   printf("The first %d elements of the sequence are: ", n);

   for (int idx = 1; idx < n; idx++) {
      prev = array[idx-1];
      if ((prev - idx) > 0 && !contains(array, idx, prev - idx)) {
         array[idx] = prev - idx;
      }
      else {
         array[idx] = prev + idx; 
      }
      printf("%d ", array[idx]);
   }
   printf("\n");
   return n;
}

static int cache[MAX_LEN];

int recaman_recursive(int number);

int recaman_recursive_wrapper(int number)
{
   if (number == 0) {
      return 0;
   }
   if (cache[number]) {
      return cache[number]; 
   }

   int result = recaman_recursive(number);
   cache[number] = result;
   return result;
}

int recaman_recursive(int number)
{


   return recaman_recursive(number);
}



int main(int argc, char* argv[])
{

   int number;

   // Catch incorrect arguments.
   if (argc != 3) {
      printf("Incorrect usage. run function with 2 arguments.\n");
      return -1;
   }
   if (!(number = atoi(argv[2]))) {
      printf("Expected integer in second argument. \n");
      return -1;
   }
   if (!(number > 0 && number < MAX_LEN)) {
      printf("Expected integer in range [1, %d]. \n", MAX_LEN);
      return -1;
   }

   printf("Recaman Sequence by Ahmad Aldasouqi\n");

   // run function
   if (*argv[1] == 'i') {
      printf("iterative recaman function. \n");
      recaman_iterative(number);
      return 0;
   }
   else if (*argv[1] == 'r') {

      printf("Running recursive recaman function. \n");

      printf("First %d elements of the sequence are: ", number);
      recaman_recursive_wrapper(number);

      return 0;
   }

   printf("First argument must be 'i' or 'r' \n");
   return -1;

}
