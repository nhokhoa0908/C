#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double sum(double a, double b, double n){
	double i, kq=0;
	for (i=0 ; i<=n ; i++){
		kq+=(a+i)/(b+i);
	}
	return kq;
}

void ABN(double* a, double* b, double* n){
	printf("Enter a: ");
	scanf("%lf", *&a);
	printf("Enter b: ");
	scanf("%lf", *&b);
	printf("Enter n: ");
	scanf("%lf", *&n);	
}


void end(){
	double x, y, z;
	ABN(&x, &y, &z);
	printf("F = %.2lf\n", sum(x, y, z));
}

int main(){
	char choice[50];
	do{
		strcpy(choice, "");
		end();
		while (strcmp(choice, "n")!=0 && strcmp(choice, "y")!=0){
			printf("Do you want to continue counting? (n=no/y=yes): ");
			fflush(stdin);
			scanf("%s", choice);
		}	
	}
	while (strcmp(choice, "n")!=0);
	printf("Goodbye!");
	return 0;
}
