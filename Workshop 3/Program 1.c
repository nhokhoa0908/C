#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Sum(int n);
int Sum(int n){
     int x=0;
     int y=0;
     while(n>=1){
           y=n%10;
		   x=x+y;
		   n=n/10; 
	 }
	 return x;
}
int main(int argc, char *argv[]) {
	int n;
	do{ a:{
		printf("Enter a positive integer \(0 exit):");
		scanf("%d",&n);}
	if(n>0) {
		printf("The sum of its decimal digits:%d\n",Sum(n));
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
