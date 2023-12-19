#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x;
	RUN_1:{
	printf ("Nhap so KW/h:");
	scanf ("%d",&x);}
	if (x<0)
		goto RUN_1;
	else if(x<=100)
		printf("Tien dien la:%d",x*950);
	else if (x<=150)
		printf("Tien dien la:%d",(x-100)*1250+95000);
	else if (x<=200)
		printf("Tien dien la:%d",(x-150)*1350+157500);
	else
		printf("Tien dien la:%d",(x-200)*1550+225000);
	return 0;
}
