#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Fibo(int n) {
	long long int f, f0=0, f1=1;
	int i=1;
	if(n>=1) printf("     %lld", f1);
	while(i<n){
		f=f0+f1;
		printf("     %lld", f);
		f0=f1;
		f1=f;
		i++;
		if((i%5)==0) printf("\n");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int n;
	do{ a:{
		printf("Enter a value of n:");
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
