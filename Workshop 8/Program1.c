#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
void menu();
void readFile(char infile[], char list[][MAX], float score[], int *n);
void writeFile(char outfile[], char list[][MAX], float score[], int *n);
char* lTrim(char list[]);
char* rTrim(char list[]);
char* trim(char list[]);
char* nameStr(char list[]);
void add(char list[][MAX], float score[], int* n);
void output(char list[][MAX], float score[], int n);
void searchbyname(char list[][MAX], int n);
void searchbyscore(char list[][MAX], float score[], int n);
void sortbyname(char list[][MAX], float score[], int n);
void sortbyscore (char list[][MAX], float score[], int n);
int getint(int min, int max);
float getfloat(float min, float max);

void menu() {
	puts("=========Menu==============");
	puts("1- Add a student into the list");
	puts("2- Print out the all list");
	puts("3- Search student by name");
	puts("4- Search student by score");
	puts("5- Sort the student list by alphabetic order by name");
	puts("6- Sort the student list in ascending order by score");
	puts("0- Exit");
}
void readFile(char infile[], char list[][MAX], float score[], int* n) {
	FILE *f;
	f = fopen(infile, "r");
	if(f != NULL) {
		while(fscanf(f, "%[^;];%f%*c", list[*n], &score[*n]) == 2) {
			(*n)++;
		}
	}
	fclose(f);
}
void writeFile(char outfile[], char list[][MAX], float score[], int* n) {
	FILE *p;
	p = fopen(outfile, "w");
	for(int i = 0; i < *n; i++) {
		fprintf(p,"%s;%.2f\n", list[i], score[i]);
	}
	fclose(p);
}
char* lTrim(char list[]) {
	int i=0;
	while(list[i] == ' ')
		i++;
	if(i > 0) strcpy(list, list + i);
	return list;
}
char* rTrim(char list[]) {
	int i = strlen(list) - 1;
	while(list[i] == ' ')
		i--;
	list[i + 1] = '\0'; //NULL
	return list;
}
char* trim(char list[]) {
	rTrim(lTrim(list));
	char *ptr = strstr(list, "  ");
	while(ptr!= NULL) {
		strcpy(ptr, ptr + 1);
		ptr = strstr(list, "  ");
	}
	return list;
}
char* nameStr(char list[]) {
	trim(list);
	strlwr(list);
	int L = strlen (list);
	int i;
	for (i = 0; i < L; i++)
		if (i == 0 || (i > 0 && list[i - 1] == ' '))
			list[i] = toupper(list[i]);
	return list;
}
void add(char list[][MAX], float score[], int* n) {
	printf("Enter name: ");
	fflush(stdin);
	gets(list[*n]);
	nameStr(list[*n]);

	score[*n] = getfloat(0, 10);
	(*n)++;
	printf("Added.\n");
}
void output(char list[][MAX], float score[], int n) {
	printf("List: \n");
	for(int i = 0; i < n; i++) {
		printf("%15s", list[i]);
		printf("%15.2f\n", score[i]);
	}
}
void searchbyname(char list[][MAX], int n) {
	int flag = 0;
	char a[MAX];
	fflush(stdin);
	printf("Enter name to search: ");
	gets(a);
	nameStr(a);
	for(int i = 0; i < n; i++) {
		char* ptr = strstr(list[i], a);
		if(ptr != NULL) {
			puts(list[i]);
			flag = 1;
		}
	}
	if(flag == 0)   printf("Name not exist.\n");
}
void searchbyscore(char list[][MAX], float score[], int n) {
	int flag = 0;
	float sc;
	printf("Enter score to search: ");
	scanf("%f", &sc);
	for(int i = 0; i < n; i++) {
		if(sc == score[i]) {
			printf("%15s", list[i]);
			printf("%15.2f\n", score[i]);
			flag = 1;
		}
	}
	if(flag == 0)   printf("Not found.\n");
}
void sortbyname(char list[][MAX], float score[], int n) {
	char list2[MAX][MAX];
	float score2[MAX];
	char t[MAX];
	float t_number;
	for(int i = 0; i < n; i++) {
		strcpy(list2[i],list[i]);
		score2[i] = score[i];
	}
	for(int i = 0; i < n - 1; i++)
		for(int j = n - 1; j > i; j--)
			if(strcmp(list2[j - 1], list2[j]) > 0) {
				strcpy(t, list2[j -1]);
				strcpy(list2[j - 1], list2[j]);
				strcpy(list2[j], t);
				t_number = score2[j - 1];
				score2[j - 1] = score2[j];
				score2[j] = t_number;
			}
	printf("After sorting: \n");
	for(int i = 0; i < n; i++) {
		printf("%15s", list2[i]);
		printf("%15.2f\n", score2[i]);
	}
}
void sortbyscore (char list[][MAX], float score[], int n) {
	char list2[MAX][MAX];
	float score2[MAX];
	int min_index;
	char t[MAX];
	float tmp;
	for (int i = 0; i < n; i++) {
		score2[i] = score[i];
		strcpy(list2[i],list[i]);
	}
	for(int i = 0; i < n - 1; i++) {
		min_index = i;
		for(int j = i + 1; j < n; j++)
			if(score2[min_index] > score2[j]) min_index = j;
		if(min_index > i) {
			tmp = score2[min_index];
			score2[min_index] = score2[i];
			score2[i] = tmp;
			strcpy(t, list2[min_index]);
			strcpy(list2[min_index], list2[i]);
			strcpy(list2[i], t);
		}
	}
	printf("After sorting: \n");
	for(int i = 0; i < n; i++) {
		printf("%15s", list2[i]);
		printf("%15.2f\n", score2[i]);
	}
}
int getint(int min, int max) {
	int value, keeptrying = 0, rc;
	char after;
	do {
		printf("Your choice: ");
		rc = scanf("%d%c", &value, &after);
		if(rc == 0) {
			keeptrying = 1;
			fflush(stdin);
		} else if(after != '\n') {
			keeptrying = 1;
			fflush(stdin);
		} else if(value < min || value > max) {
			keeptrying = 1;
			fflush(stdin);
		} else keeptrying = 0;
	} while(keeptrying == 1);
	return value;
}
float getfloat(float min, float max) {
	float value;
	int keeptrying = 0, rc;
	char after;
	do {
		printf("Enter score: ");
		rc = scanf("%f%c", &value, &after);
		if(rc == 0) {
			keeptrying = 1;
			fflush(stdin);
		} else if(after != '\n') {
			keeptrying = 1;
			fflush(stdin);
		} else if(value < min || value > max) {
			keeptrying = 1;
			fflush(stdin);
		} else keeptrying = 0;
	} while(keeptrying == 1);
	return value;
}
int main() {
	int op;
	int n = 0;
	char list[MAX][MAX];
	float score[MAX];
	char infile[] = "students1.txt";
	char outfile[] = "students2.txt";
	readFile(infile, list, score, &n);
	output(list, score, n);
	do {
		menu();
		op = getint(0, 6);
		switch(op) {
			case 1:
				add(list, score, &n);
				break;
			case 2:
				for(int i = 0; i < n; i++)
					nameStr(list[i]);
				output(list, score, n);
				break;
			case 3:
				searchbyname(list, n);
				break;
			case 4:
				searchbyscore(list, score, n);
				break;
			case 5:
				sortbyname(list, score, n);
				break;
			case 6:
				sortbyscore(list, score, n);
				break;
		}
	}    while(op != 0);
	if(op == 0)
		printf("Goodbye!");
	writeFile(outfile, list, score, &n);
	return 0;
}

