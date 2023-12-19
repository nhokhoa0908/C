#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getint(int min, int max);
int main(int argc, char *argv[])
{  int x, y, total, count = 0; 
   srand(time(NULL));
   
   printf("Dice thrower\n=============");
   fflush(stdin);
   total = getint(2, 12);

   do 
   {   x = rand() % 6 + 1;  //1 -> 6//
       y = rand() % 6 + 1;
       printf("Result of throw %d: %d + %d\n", ++count, x, y);
       sleep(1);
   }
   while(x + y != total);
   sleep(1);
   printf("You got your total in %d throw!", count);
   return 0;
}
int getint(int min, int max)
{  int value, keeptrying = 1, rc;
   char after;
   do 
   {   printf("\nTotal sought: "); 
       rc = scanf("%d%c", &value, &after);
       if(rc == 0)
       {  printf("No input accepted!\n\n");
          fflush(stdin);
	   }
	   else if(after != '\n')
	   {  printf("Trailing characters!\n\n");
	      fflush(stdin);
	   }
	   else if(value < min || value > max)
	   {  printf("Out of range!\n\n");  }
	   else    
	      keeptrying = 0;
   }
   while(keeptrying == 1);
   return value;
}

