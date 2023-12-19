#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double x,y;
	char op;
	int m,n;
	RUN_1:
	printf("Nhap so x: ");
	scanf("%lf", &x);
	printf("Nhap so y: ");
	scanf("%lf", &y);
	printf("Nhap phep toan cua ban: ");
	fflush(stdin);
	scanf("%c", &op);
	switch(op) {
		case '+':
			if(x)
				printf ("Ket qua la:%lf",x+y);
			break;
		case '-':
			printf ("Ket qua la:%lf",x-y);
			break;
		case '*':
			printf ("Ket qua la:%lf",x*y);
			break;
		case '/':
			if(y=0)
				printf("Divived by 0 is undefined");
			else
				printf ("Ket qua la:%lf",x/y);
			break;
		case '%':
			m = (int) x;
			n = (int) y;
			if ((x-m != 0 || y-n != 0)) {				
				goto RUN_1;
			}
			if ((x-m == 0 && y-n == 0)) {
				printf("So du a chia cho b la: %d", m%n);
			}
	}

	return 0;
}
