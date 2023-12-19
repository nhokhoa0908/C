#include<stdio.h>
#include<stdlib.h>
int isPrime(int k);
void printPrimes(int n);
//main program//
int main()
{  int n;
   do { printf("Enter a positive integer: ");
        scanf("%d", &n);
      }
   while (n <= 1);
   printf("Primes from 2 to %d:\n", n);
   printPrimes(n);
   return 0;
}
//check if j (j <= n) is a prime or not//
int isPrime(int k)
{   int result = 1, i;
    for (i = 2; i*i <= k; i++)
        if (k%i == 0) result = 0;
	return result;
}
//print out primes from 2 to n//
void printPrimes(int n)
{    int j = 2;
     while (j <= n)
     { if (isPrime(j) == 1) printf("%5d", j);
       j++;
     }
}
