#include <stdio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
a1 :

	printf("Enter a positive integer:");
	scanf("%d",&n);
	if(n<=0) {
		goto a1;
	}

	else {

		int count=0;
		int m=2;
		while(1) {
			int mark =1;
			int i;
			for(i=2; i<=sqrt(m); i++) { //sqrt can bac 2
				if(m%i ==0) {
				    mark=0;
				    break;
				}
			}
			if (mark==1) {
				count++; //co them 1 so nguyen to
				printf("%3d",m);
			}
			if(count >=n) {
				break;
			}
			m++;
		}
	}
	return 0;
}
