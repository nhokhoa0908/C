include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Them(int* a);
void Tim(int* a, int val);
void Xoa1(int* a, int val);
void XoaHet(int* a, int val);
void Output(int* a);
void Chan(int* a);
int Max(int* a);
void Khoang(int* a, int min, int max);
void Bubble(int*a,int*b);


int n=-1;
void menu() {
	int op=1, o, val;
	int* a;
	int* b;
	a=(int*)malloc((n+1)*sizeof(int));
	b=(int*)malloc((n+1)*sizeof(int));
	while(op!=0) {
		printf("=================MENU=================\n\n");
		printf("\n1-Add a value\n2-Search a value\n3-Delete a value first\n4-Delete all value\n5-Print out the array\n6-Print out even value in array\n7-Print out max value in array\n8-Print out value in a range\n9-Print out the array in ascending order(bubble sort)\n0-Quit");
		printf("\nEnter a number:");
		scanf("%d", &op);
		switch(op) {
			case 1: {
				n++;
				Them(a);
				printf("\nAdd success\n\n");
				break;
			}
			case 2: {
				printf("\nEnter a value: ");
				scanf("%d", &val);
				Tim(a, val);
				printf("\n\n");
				break;
			}
			case 3: {
				printf("\nEnter a value: ");
				scanf("%d", &val);
				Xoa1(a, val);
				printf("\n\n");
				break;
			}
			case 4: {
				printf("\nEnter a value: ");
				scanf("%d", &val);
				XoaHet(a, val);
				printf("\n\n");
				break;
			}
			case 5: {
				printf("\nYour array: ");
				Output(a);
				printf("\n\n");
				break;
			}
			case 6: {
				printf("\nEven values: ");
				Chan(a);
				printf("\n\n");
				break;
			}
			case 7: {
				printf("\nMax value in Array: %d", Max(a));
				printf("\n\n");
				break;
			}
			case 8: {
				int x, y;
				printf("\nEnter a minimum value in range: ");
				scanf("%d", &x);
				printf("Enter a maximum value in range: ");
				scanf("%d", &y);
				Khoang(a,x,y);
				printf("\n\n");
				break;
			}
			case 9: {
					Bubble(a, b);
					printf("\nAfter sort: ");
					Output(b);
					printf("\n\n");
				break;
			}
			case 0: {
				printf("\nGoodbye!");
				break;
			}
			default: {
				printf("\nRe-enter\n", op);
				break;
			}
		}
	}
}

int Them(int* a) {
	int keeptrying=1, rc;
	char after;
	do {
		printf("\nEnter a value: ");
		rc=scanf("%d%c", &a[n], &after);
		if(rc==0) {
			fflush(stdin);
		} else {
			if(after!='\n') {
				fflush(stdin);
			} else keeptrying=0;
		}
	} while(keeptrying==1);
}
void Tim(int* a, int val) {
	int id=0;
	for(int i=0; i<=n; i++) {
		if(a[i]==val) {
			printf("\nIndex %d", i);
			id++;
		}
	}
	if(id==0)
		printf("\n%d is not exist in Array!", val);
}
void Output(int* a) {
	for(int i=0; i<=n; i++) 
	printf(" %d ", a[i]);
}
void Xoa1(int* a, int val) {
	int id=0;
	for(int i=0; i<=n; i++) {
		if(a[i]==val) {
			for(int j=i; j<=n; j++)
				a[j]=a[j+1];
			id++;
			break;
		}
	}
	if(id==0)
		printf("\n%d is not exist in Array!", val);
	else {
		n=n-id;
		printf("\nArray after remove: ");
		Output(a);
	}
}
void XoaHet(int* a, int val) {
	int id=0;
	for(int i=0; i<=n; i++) {
		if(a[i]==val) {
			for(int j=i; j<=n; j++)
			a[j]=a[j+1];
			id++;
			i--;
		}
	}
	if(id==0)
		printf("\n%d is not exist in Array!", val);
	else {
		n=n-id;
		printf("\nArray after remove: ");
		Output(a);
	}
}
void Chan(int* a) {
	int id=0;
	for(int i=0; i<=n; i++) {
		if((a[i]%2) == 0) {
			printf(" %d ", a[i]);
			id++;
		}
	}
	if(id==0)
		printf("\nNo even value in Array!\n");
}
int Max(int* a) {
	int Max=a[0];
	for(int i=1; i<=n; i++) {
		if(a[i]>Max)
			Max=a[i];
	}
	return Max;
}
void Khoang(int* a, int x, int y) {
	int count=0;
	for(int i=0; i<=n; i++) {
		if((a[i]>=x) && (a[i]<=y)) {
			printf(" %d ",a[i]);
			count++;
		}
	}
	if(count==0)
		printf("\nNo value in range!");
}
void Bubble(int* a,int* b) {
	int temp;
	for(int i=0; i<=n; i++)
	b[i]=a[i];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			if(b[j]>b[j+1]){
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	menu();
	return 0;
}
