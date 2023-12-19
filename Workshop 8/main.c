#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu();
int getInt(int min, int max);
void add(char list[][MAX],double score[],int *n);
char* nameStr(char s[]);
char* trim(char s[]);
char* rtrim(char s[]);
char* ltrim(char s[]);
void output(char list[][MAX],double score[],int n);
void searchname(char list[][MAX], int n);
void searchscore(char list[][MAX],double score[],int n);
void sortbyname(char list[][MAX],double score[],int n);
void sortbyscore(char list[][MAX],double score[],int n);
void readfile(char filein[], char list[][MAX],double score[],int *n);
void writefile(char fileout[] ,char list[][MAX],double score[],int *n);

void add(char list[][MAX],double score[],int* n){
	++*n;
	printf("Enter name: ");
	fflush(stdin);
	gets(list[*n]);
	nameStr(list[*n]);
	printf("Enter score: ");
	fflush(stdin);
	scanf("%lf", &score[*n]);
}

void output(char list[][MAX],double score[],int n){
	int i;
	printf("List: \n");
	for (i=0; i<=n; i++){
		printf("%20s", list[i]); 
		printf("%20.1lf\n", score[i]);
	}
}

void searchname(char list[][MAX], int n){
	int i, flag=0;
	char search[MAX];
	printf("Enter name want to search: ");
	fflush(stdin);
	gets(search);
	
	for(i=0; i<=n; i++){	
		if(strstr(list[i], search)!=NULL){
			flag =1;
			printf("%20s\n", list[i]);
			
		}
	}
	if(flag==0) printf("Name does not exist!\n");
}

void searchscore(char list[][MAX],double score[],int n){
	double item;
	int i, flag=0;
	printf("Enter a score want to search: ");
	scanf("%lf",&item);
	for(i=0; i<=n; i++){
		if(score[i]==item){
			flag=1;
			printf("%20s",list[i]);
			printf("%20.2lf\n", score[i]);	
		}
	}
	if(flag==0) printf("Not exist!!\n");	
}

void sortbyscore(char list[][MAX],double score[],int n){
	char list2[MAX][MAX];
	double score2[MAX];
	int i,j;
	char t[MAX];
	double t_number;
	//copy
	for(i=0; i<=n; i++){
		strcpy(list2[i],list[i]);
		score2[i]= score[i];
	}
	//sort
	for(i=0; i<=n;i++){
		for(j=n; j>=i; j--){
			if(score2[j-1]>score2[j]){
				strcpy(t,list2[j]);
				strcpy(list2[j],list2[j-1]);
				strcpy(list2[j-1],t);
				
				t_number = score2[j];
				score2[j] = score2[j-1];
				score2[j-1]= t_number;
			}
		}
	}
	//print
	for(i=0; i<=n; i++){
		printf("%20s",list2[i]);
		printf("%20.2lf\n",score2[i]);
	}
}

void sortbyname(char list[][MAX],double score[],int n){
	char list2[MAX][MAX];
	double score2[MAX];
	int i,j;
	char t[MAX];
	double t_number;
	//copy
	for(i=0; i<=n; i++){
		strcpy(list2[i],list[i]);
		score2[i]= score[i];
	}
	//sort
	for(i=0; i<=n; i++){
		for(j=n; j>=i; j--){
			if(strcmp(list2[j-1],list2[j])>0){
				strcpy(t,list2[j]);
				strcpy(list2[j],list2[j-1]);
				strcpy(list2[j-1],t);
				
				t_number = score2[j];
				score2[j] = score2[j-1];
				score2[j-1]= t_number;
			}
		}
	}
	//print
	for(i=0; i<=n; i++){
		printf("%20s",list2[i]);
		printf("%20.2lf\n",score2[i]);
	}
}

char* lTrim(char s[]){
	int i = 0;
	while(s[i]==' ') i++;
	if(i>0) strcpy(&s[0],&s[i]);
	return s;
}

char* rTrim(char s[]){
	int i = strlen(s)-1;
	while(s[i]==' ') i--;
	s[i+1]='\0';
	return s;
}

char* trim(char s[]){
	rTrim(lTrim(s));
	char *ptr= strstr(s, "  ");
	while (ptr!=NULL) /* While two blanks exist*/
	{	strcpy(ptr, ptr+1); /* remove one blank*/
	ptr = strstr(s, "  ");
	}
	return s;
}

char* nameStr(char s[]){
	trim(s); /*trim all extra blank*/
	strlwr(s); /* lowercase s*/
	int L = strlen(s);
	int i;
	for (i=0; i<L; i++)
		if(i==0 || (i>0 && s[i-1]== ' ')) s[i]= toupper(s[i]);
	return s;
}

int getInt(int min, int max){
	int value, keeptrying = 1, rc;
	char after;
	do	{
		printf("Your choice: ");
	rc = scanf("%d%c", &value, &after);
	if (rc==0) {
		fflush(stdin);
	} else if(after !='\n'){
		printf("**Trailing a character\n\n");
		fflush(stdin);
	}else
		keeptrying=0;
	}while (keeptrying == 1);
	return value;
}
void readfile(char filein[], char list[][MAX],double score[],int *n)
{
    FILE* f = fopen(filein,"r");
    if(f != NULL)
    {
        while(fscanf(f,"%[^;];%lf%*c",list[*n],&score[*n])==2)
        {
            (*n)++;
        }
        fclose(f);
    }
}
void writefile(char fileout[] ,char list[][MAX],double score[],int *n)
{
    FILE* p = fopen(fileout,"w");
    for(int i=0;i<*n;i++)
    {
        fprintf(p,"%15s;%10.2lf\n",list[i],score[i]);
    }
    fclose(p);
}

void menu(){
	printf("\n========MENU=======\n\n");
	printf("1-Add a student into the list\n");
	printf("2-Print out the all list\n");
	printf("3-Search student by name\n");
	printf("4-Search student by score\n");
	printf("5-Sort the student list by alphabetic order by name\n");
	printf("6-Sort the student list in ascending order by score\n");
	printf("0-Exit\n");
}

int main(int argc, char *argv[]) {
	char filein[] = "students1.txt";
	char fileout[] = "students2.txt";
	int n=-1;
	int op;
	char list[MAX][MAX];
	double score[MAX];
    readfile(filein,list,score,&n);
    output(list,score,n);
	do {
		menu();
		op=getInt(0,6);
		switch(op){
		case 0:
			printf("Goodbye!");
			break;
		case 1:
			add(list, score, &n);
			break;
		case 2:
			output(list, score, n);
			break;
		case 3:
			searchname(list, n);
			break;
		case 4:
			searchscore(list, score, n);
			break;
		case 5:
			sortbyname(list, score, n);
			break;
		case 6:
			sortbyscore(list, score, n);
			break;
		}
	} while (op!=0);
	writefile(fileout,list,score,&n);
	return 0;
}
