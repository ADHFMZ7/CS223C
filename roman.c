#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int rchar_to_int(char numeral)
{
   switch(numeral) {
      case 'I': return 1;
      case 'V': return 5;
      case 'X': return 10;
      case 'L': return 50;
      case 'C': return 100;
      case 'D': return 500;
      case 'M': return 1000;
      default:  printf("invalid symbol %c\n", numeral);
   }
   exit(-1);
}


int roman_to_int(char *string)
{
   if (string == NULL || !string[0]) {
      return -1;
   }

   int idx = 0;
   char cur = string[idx];
   int num;
   int next_num;
   int result = 0;

   while (cur) {
      num = rchar_to_int(cur);
      next_num = (string[idx+1] != 0) ? rchar_to_int(string[idx+1]) : 0;

      if (num >= next_num) {
         result += num;      
      }
      else {
         result -= num;
      }
      cur = string[++idx];
   }
   return result;
}

int tests() 
{
   assert(roman_to_int("MMMLI") == 3051);
   assert(roman_to_int("MMMDCCCLXXXVIII") == 3888);
   assert(roman_to_int("MMMMDCCCLXXXVIII") == 4888);
   assert(roman_to_int("XI") == 11);
   return 0;
}


int main(int argc, char **argv)
{

   // if (argc != 2) {
   //    printf("Improper arguments. Program expects one string.\n");
   //    printf("Ex) ./output IIIV\n");
   //    return -1;
   // }
   //
   // printf("The number in roman numerals is %d\n", roman_to_int(argv[1]));
   //
   tests();
   return 0;
}

