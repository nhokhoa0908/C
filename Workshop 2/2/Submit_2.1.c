#include<stdio.h>
#include<stdlib.h>
void printDivisors(int N);
int sumDivisors(int N);
//main program//
int main()
{  int n, i, sum;
   do { printf("Enter a positive integer: ");
        scanf("%d", &n);
      }
   while (n <= 0);
   printDivisors(n);
   sum = sumDivisors(n);
   printf("\nSum: %d", sum);
   return 0;
}
//print out the divisors of n//
void printDivisors(int N)
{  int i;
   for (i = 1; i <= N/2; i++)
     if (N%i == 0) printf("%7d", i);
}
//calculate sum of the divisors of n//
int sumDivisors(int N)
{  int i, S = 0;
   for (i = 1; i <= N/2; i++)
     if (N%i == 0) S += i;
   return S;
}
