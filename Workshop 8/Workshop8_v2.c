#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
	char name[100];
	float mark;
};
typedef struct student student;

student s[100];
int n=0;

void clear(){
	while (getchar() != '\n');
}

int get_int(char ins[100]){
	int t, check, lap=1;
	char after;
	do{
		printf(ins);
		check = scanf("%d%c", &t, &after);
		if (check==0) clear();
		else if (after!='\n') clear();
			else lap=0;
	}
	while (lap==1);
	return t;
}

void modify(char a[100]){
	int i=0;
	while (a[i]==' ') i++;
	if (i>0) strcpy(&a[0], &a[i]);
	i=strlen(a)-1;
	while (a[i]==' ') i--;
	a[i+1]='\0';
	char *p = strstr(a,"  ");
	while (p!='\0'){
		strcpy(p,p+1);
		p = strstr(a,"  ");
	}
	strlwr(a);
	for (i=0 ; i<strlen(a) ; i++){
		if (i==0 || (i>0 && a[i-1]==' ')) a[i]=toupper(a[i]);
	}
}

void add(student s[100], int* n){
	printf("Enter name: ");
	gets(s[*n].name);
	modify(s[*n].name);
	printf("Enter mark: ");
	scanf("%f", &s[*n].mark);
	(*n)++;
	printf("Add successfully !!!");
}

void print_out_one(student s){
	printf("|%-20s|%5.2f|\n", s.name, s.mark);
}

void print_out_all(student s[100], int n){
	int i;
	printf("|        Name        | Mark |\n");
	for (i=0 ; i<n ; i++){
		printf("|%-20s|%6.2f|\n", s[i].name, s[i].mark);
	}
}

void search_name(student s[100], char fname[100], int n){
	int i, flag=0;
	for (i=0 ; i<n ; i++){
		if (strstr(s[i].name, fname)!='\0'){
			print_out_one(s[i]);
			flag=1;
		}
	}	
	if (flag==0) printf("No one whose name is %s in the list !!!\n", fname);
}

void search_mark(student s[100], float fmark, int n){
	int i, flag=0;
	for (i=0 ; i<n ; i++){
		if (fmark==s[i].mark){
			print_out_one(s[i]);
			flag=1;
		}
	}
	if (flag==0) printf("No one whose mark is %.2f in the list !!!\n", fmark);
}

void swap(student *s1, student *s2){
	student temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void sort_name(student s[100], int n){
	student stemp[100];
	int i, j;
	for (i=0 ; i<n ; i++) stemp[i]=s[i];
	for (i=0 ; i<n-1 ; i++)
		for (j=n-1 ; j>i ; j--)
			if (strcmp(stemp[j].name, stemp[j-1].name)<0) swap(&stemp[j], &stemp[j-1]);
	print_out_all(stemp, n);
}

void sort_mark(student s[100], int n){
	student stemp[100];
	int i, j;
	for (i=0 ; i<n ; i++) stemp[i]=s[i];
	for (i=0 ; i<n-1 ; i++)
		for (j=n-1 ; j>i ; j--)
			if (stemp[j].mark < stemp[j-1].mark) swap(&stemp[j], &stemp[j-1]);
	print_out_all(stemp, n);
}

void read_file(char file_name[100], student s[100], int* n){
	FILE* f = fopen(file_name, "r");
	if (f!=NULL){
		while (fscanf(f,"%[^;];%f%*c", s[*n].name, &s[*n].mark)==2) (*n)++;
		fclose(f);
	}
	
}

void write_file(char file_name[100], student s[100], int n){
	FILE* f = fopen(file_name, "w");
	int i;
	for (i=0 ; i<n ; i++){
		char t[100];
		sprintf(t, "%f", s[i].mark);
		int j=strlen(t)-1;
		while (t[j]=='0') j--;
		t[j+1]='\0';
		if (t[j]=='.') t[j]='\0';
		fprintf(f, "%s; %s\n", s[i].name, t);
	}
	fclose(f);
}

void menu(){
	int choice;
	system("cls");
	print_out_all(s,n);
	printf("===============MENU===============\n\n");
	printf("1. Add a student\n");
	printf("2. Show student list\n");
	printf("3. Search by name\n");
	printf("4. Search by mark\n");
	printf("5. Sorted by name\n");
	printf("6. Sorted by score\n");
	printf("0. Exit\n");
	choice = get_int("Enter your choice: ");
	switch (choice){
		case 1:{
			do{
				system("cls");
				printf("========== Add a student ==========\n\n");
				add(s, &n);
				printf("\n1. Continue\n0. Menu\n");
				do choice=get_int("Enter your choice: ");
				while (choice!=1 && choice!=0);
			}
			while (choice==1);
			menu();
			break;
		}
		case 2:{
			system("cls");
			printf("========== Print out student list ==========\n\n");
			if (n>0) print_out_all(s, n);
			else printf("Null list !!!\n");
			printf("\nPress any key to continue...");
			getch();
			menu();			
			break;
		}
		case 3:{
			if (n>0)
				do{
					char fname[100];
					system("cls");
					printf("========== Search by name ==========\n\n");
					printf("Enter name: ");
					scanf("%s", fname);
					modify(fname);
					search_name(s, fname, n);
					printf("\n1. Continue\n0. Menu\n");
					do{
						choice=get_int("Enter your choice: ");
					} while (choice!=1 && choice!=0);
				} while (choice==1);
			else{
				system("cls");
				printf("========== Search by name ==========\n\n");
				printf("Null list !!!\n");
				printf("Press any key to continue...");
				getch();
			}
			menu();
			break;
		}
		case 4:{
			if (n>0)
				do{
					float fmark;
					system("cls");
					printf("========== Search by mark ==========\n\n");
					printf("Enter mark: ");
					scanf("%f", &fmark);
					search_mark(s, fmark, n);
					printf("\n1. Continue\n0. Menu\n");
					do{
						choice=get_int("Enter your choice: ");
					}
					while (choice!=1 && choice!=0);					
				}
				while (choice==1);
			else{
				system("cls");
				printf("========== Search by name ==========\n\n");
				printf("Null list !!!\n");
				printf("Press any key to continue...");
				getch();				
			}
			menu();
			break;
		}
		case 5:{
			system("cls");
			printf("========== Sorted by name ==========\n\n");
			if (n>0) sort_name(s,n);
			else printf("Null list !!!");
			printf("\nPress any key to continue...");
			getch();
			menu();
			break;
		}
		case 6:{
			system("cls");
			printf("========== Sorted by mark ==========\n\n");
			if (n>0) sort_mark(s,n);
			else printf("Null list !!!");
			printf("\nPress any key to continue...");
			getch();
			menu();
			break;
		}
		case 0:{
			system("cls");
			write_file("students2.txt", s, n);
			printf("			****  *   * *****  *  *  *\n");
			printf("			*   *  * *  *      *  *  *\n");
			printf("			* **    *   *****  *  *  *\n");
			printf("			*   *   *   *\n");
			printf("			****    *   *****  *  *  *\n");
			printf("\nPress any key to continue...");			
			getch();
			exit(0);
			break;
		}
		default:{
			printf("Not updated !!!\nPress any key to continue...");
			getch();
			menu();
			break;
		}
	}
}
int main(){
	read_file("students1.txt", s, &n);
	menu();
	return 0;
}
