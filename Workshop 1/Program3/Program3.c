#include<stdio.h>
#include<stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	int noDigit=0,noLetter=0,noOther=0;
	char c=NULL;
	printf("Enter a string:");
	while (c!='\n') {
		c = getchar();
		if ('0'<=c && c<='9') noDigit++;
		else if (('a'<=c && c<='z') || ('A'<=c && c<='Z')) noLetter++;
			else noOther++;
	}
	printf("Digits:%d\n",noDigit);
	printf("Letters:%d\n",noLetter);
	printf("Others:%d\n",noOther-1);
	return 0;

}
