#include<stdio.h>
#include<stdlib.h>
int gcd(int a, int b);
int lcm(int a, int b);
//main program//
int  main()
{  int m, n, G, L;
   do { printf("Enter two positive integers: ");
        scanf("%d %d", &m, &n);
      }
   while (m <= 0 || n <= 0);
   G = gcd(m, n);
   L = lcm(m, n);
   printf("GCD: %d\nLCM: %d", G, L);
   return 0;
}
//calculate the gcd of two positive integers//
int gcd(int a, int b)
{  while (a != b)
     if (a > b) a -=b;
     else b -= a;
   return a;
}
//calculate the lcm of two positive integers//
int lcm(int a, int b)
{  return (a*b)/gcd(a, b);
}

