#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c1,c2,x,y;
	printf("Enter first characters:\n");
	scanf("%c",&c1);
	printf("Enter second characters:\n");
	fflush(stdin);
	scanf("%c",&c2);	
	printf("Charater Dec Octal Hex\n");
	if(c1>c2) {
		x=c1;
		c1=c2;
		c2=x;
	}
	for (y=c1; y<=c2; y++) {

		printf("%8c %3d %5o %3x\n",y,y,y,y);
	}

 return 0;
}
