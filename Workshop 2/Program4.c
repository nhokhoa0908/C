#include <stdio.h>

int UCLN(int a,int b){
    if (a%b!=0)
        return UCLN(b,a%b);
    else
        return b;
}

int BCNN(int a,int b){
    return (a*b)/UCLN(a,b);
}

int main(){
    int a,b,ucln,bcnn;
	a1 :	
    printf("Enter two positive integers: ");
    scanf("%d%d",&a,&b);
    if(a>0&&b>0){
    ucln = UCLN(a,b);
    printf("GCD=%d\n",ucln);
    bcnn = BCNN(a,b);
    printf("LCM=%d\n",bcnn);}
    else goto a1;
    return 0;
}
