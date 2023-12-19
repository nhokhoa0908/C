#include <stdio.h>
#include <stdlib.h>
	int getInt(int min,int max){
		int value, keeptrying=1,rc;
	    char after;
	do {
		printf("Enter a whole number in range[%d,%d]:",min,max);
		rc=scanf("%d%c",&value,&after);
		if (rc==0){
			printf("**No input accepted!**\n\n");
			fflush(stdin);	
		}else if(after!='\n'){
			printf("**Trailing characters!**\n\n");
			fflush(stdin);
		}else if(value<min||value>max){
			printf("**Out of range!**\n\n");
		}else
		    keeptrying=0;
	}while(keeptrying==1);
	return value;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	int x,y,total,count=1,check;
	printf("Dice thrower\n===========");
    do {
    	printf("\nTotal sought:");
    	fflush(stdin);
    	check=scanf("%d",&total);
    	if(check!=1||total<2||total>12)
				total=getInt(2,12);  
	}while (check!=1||total<2||total>12);
	do{
		x=rand()%6+1;
		y=rand()%6+1;
		Sleep(1000);
		printf("Result of throw %d : %d + %d\n",count++,x,y);
	}while(x+y!=total);
	Sleep(1000);
	printf("You got your total in %d throws!",count);
	return 0;
}
