#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int checkPrime(int n){
	int flag=1;
	 for (int i =2;i<(n);i++)
	    if(n%i==0){
	    	flag=0;
	    	break;
		}
	return flag;
}
void print_x_Prime(int x){
	for(int j=2; j<=x;j++){
		if(checkPrime(j))
		   printf("%5d",j);
	}
}

int main(int argc, char *argv[]) {
	int x;
	a1 :
	
		printf("Enter a positive integer:");
		scanf("%d",&x);
	 if(x>=2){
	      printf("Prime from 2 to %d:\n",x);
	      print_x_Prime(x);}
	    else goto a1;
	return 0;
}
