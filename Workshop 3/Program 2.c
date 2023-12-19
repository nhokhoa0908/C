#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Fibo(int x) {
	int f, f0=1, f1=1, d=0;
	if(x==1) printf("%d is a Fibonacci number", x);
	do {
		f=f0+f1;
		f0=f1;
		f1=f;
		if(f==x) {
			d=1;
			break;
		}
	} while(f<=x);
	if(d==1) printf("%d is a Fibonacci \n", x);
	else printf("%d isn't a Fibonacci \n", x);
}
int main(int argc, char *argv[]) {
	int n;
	do{ a:{
		printf("Enter a positive integer \(0 exit):");
		scanf("%d",&n);}
	if(n>0) {
		Fibo(n);
	} else {
		if(n<0) {
			goto a;
		} else {
			printf("Goodbye!");
			break;
		}
	}}
	while(n!=0);
	return 0;
}
