#include<stdio.h>
#include<conio.h>
#include<string.h>
struct data{
	char list[1000];
	char date[1000];
	int no, stat;
}dat;

int create(){
	printf("\n");
	FILE *fp; 
	if((fp = fopen("To Do List.csv", "w+")) == NULL){
		printf("Error!\n"); return 0;
	} fprintf(fp, "ID NO;Activities List;Deadline;Status\n"); int x; 
	printf("How many data do u want 2 add? "); scanf("%d", &x); getchar();
	for(int i=0; i < x; i++){
		printf("ID No\t\t\t: "); scanf("%d", &dat.no); getchar();
		printf("Enter Activities\t: "); scanf("%[^\n]", &dat.list); getchar();
		printf("Enter Deadline\t\t: "); scanf("%[^\n]", &dat.date); getchar();
		printf("Statuses(1/0)\t\t: "); scanf("%d", &dat.stat); getchar();
		printf("\n");
		fprintf(fp, "%d;%s;%s;%d\n",dat.no, dat.list, dat.date, dat.stat);
	} fclose(fp); 
}

int read(){
	printf("\n");
	FILE *fp;
	if((fp = fopen("To Do List.csv", "r")) == NULL){
		printf("Error!\n"); return 0;
	} char line[200];
	while(fgets(line, sizeof(line), fp)){
		char *display = strtok(line, ";\n");
		while(display != NULL){
			printf("%-20s", display);
			display = strtok(NULL, ";\n");
		} printf("\n");
	} fclose(fp); printf("\n");
}

int append(){
	printf("\n");
	FILE *fp;
	fp = fopen("To Do List.csv", "a");
	int x;
	if(fp == NULL){
		printf("Error!\n"); return 0;
	} printf("How many data do u want 2 add? "); scanf("%d", &x); getchar();
	for(int i=0; i < x; i++){
		printf("ID No\t\t\t: "); scanf("%d", &dat.no); getchar();
		printf("Enter Activities\t: "); scanf("%[^\n]", &dat.list); getchar();
		printf("Enter Deadline\t\t: "); scanf("%[^\n]", &dat.date); getchar();
		printf("Statuses(1/0)\t\t: "); scanf("%d", &dat.stat); getchar();
		printf("\n");
		fprintf(fp, "%d;%s;%s;%d\n",dat.no, dat.list, dat.date, dat.stat);
	} fclose(fp);
}

int main(){
	int num; 
	printf("\t\t\t\t=================TO DO LIST================\n");
	printf("\t\t\t\t\t\tCreated by: Pristian Budi D\n");
	printf("\t\t\t\t\t\t\t\tVer 2.1.0.5\n");
	do{
		printf("OPTIONS:\n"); printf("1. CREATE NEW DATA\n"); printf("2. DISPLAY DATA\n"); printf("3. APPEND DATA\n"); printf("0. EXIT\n");
		scanf("%d", &num, printf("\n\nInput your choices: "));
		switch(num){
			case 1:
				create(); break; 
			case 2:
				read(); break;
			case 3:
				append(); break;
		}
	} while(num!=0); return 0;
}
