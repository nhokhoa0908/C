#include<stdio.h>
#include<stdlib.h>
int isPrime(int k);
void print_n_Primes(int N);
//main program//
int main()
{  int n;
   do { printf("Enter n: ");
        scanf("%d", &n);
      }
   while (n <= 0);
   printf("Result of the first %d primes:\n", n);
   print_n_Primes(n);
   return 0;
}
//check primes//
int isPrime(int k)
{  int result = 1, i;
   for (i = 2; i*i <= k; i++)
      if (k%i == 0) result = 0;
   return result;
}
//print out the first n primes//
void print_n_Primes(int N)
{  int count = 0; //count primes printed//
   int value = 2; //current value is considered//
   while (count < N)
   {  if (isPrime(value) == 1)
        {  printf("%5d", value);
           count++;
	    }
   value++;
   }
}
