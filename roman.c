#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int rchar_to_int(char numeral)
{
   switch(numeral) {
      case 'i': return 1;
      case 'v': return 5;
      case 'x': return 10;
      case 'l': return 50;
      case 'c': return 100;
      case 'd': return 500;
      case 'm': return 1000;
      //Capital letters are multiplied by 1000
      case 'I': return 1 * 1000;
      case 'V': return 5 * 1000;
      case 'X': return 10 * 1000;
      case 'L': return 50 * 1000;
      case 'C': return 100 * 1000;
      case 'D': return 500 * 1000;
      case 'M': return 1000 * 1000;
      default:  printf("invalid symbol %c\n", numeral);
   }
   exit(1);
}


int roman_to_int(char *string)
{
   if (string == NULL || !string[0]) {
      return -1;
   }

   int idx = 0;
   char cur = string[idx];
   int num, next_num;
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


int main(int argc, char **argv)
{

   if (argc != 2) {
      printf("Improper arguments. Program expects one string.\n");
      printf("Ex) ./output IIIV\n");
      return -1;
   }

   printf("The number in roman numerals is %d\n", roman_to_int(argv[1]));

   tests();
   return 0;
}

