#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sum (int n) {
	int i,x=0;
    for ( i=1;i<n;i++){
	
	   if (n % i == 0) {
	   
            x +=	i ;	 	
       printf("%d\n",i);}
   }
      	printf("\n");
    printf ("Sum:%d\n",x);
   
return x;
}

int main(int argc, char *argv[]) {

	int n;
	RUN_1:
	printf("Enter positive integer:");
	scanf("%d",&n);
	if (n<=0){ goto RUN_1;
	}
	else
	sum (n);

    
	return 0;
}
