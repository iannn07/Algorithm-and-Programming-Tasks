#include<stdio.h>
#include<string.h>
struct mhs{
	long long int nim; float gpa; char name[20]; int age;
} maha[20], gpaSort, nameSort, ageSort;

void sort(int x){
	//Here's the difference between bubble & selection
	for(int i=0; i < x; i++){ //Moving each element
		for(int j=i+1; j < x; j++){ //Search for min. element
			if(maha[j].gpa < maha[i].gpa){
				//Swapping each element
				gpaSort = maha[j]; maha[j] = maha[i]; maha[i] = gpaSort;
			} else if(maha[i].gpa == maha[j].gpa){
				/*According to the Terms & Condition, so
				We used if nest to sort by name*/
				if(strcmp(maha[i].name, maha[j].name) > 0){
					//Use strcmp to compare between char by char inside of array
					nameSort = maha[j]; maha[j] = maha[i]; maha[i] = nameSort;	
				}
			}
		}
	}
}

int main(){
	//Headline
	printf("\t\t\t============= C Program Student Sorting by GPA & Name =============\n");
	printf("\t\t\t\t\t\t\t\tCreated by: Pristian Budi D\n"); 
	printf("\t\t\t\t\t\t\t\t\t\tVer 2.19.20\n\n\n");
	
	//Variable declaring & Total Students 
	int x, i; scanf("%d", &x, printf("How many students do u want to input? ")); getchar();
	
	//Input Data
	for(i=0; i < x; i++){
		printf("\nStudent #%d: \n", i+1);
		scanf("%[^\n]*%c", &maha[i].name, printf("Input Student Name\t\t: ")); getchar();
		scanf("%lld", &maha[i].nim, printf("Input Student ID\t\t: ")); getchar();
		scanf("%f", &maha[i].gpa, printf("Input Student GPA\t\t: ")); getchar();
		scanf("%d", &maha[i].age, printf("Input Student Age\t\t: ")); getchar();
	} printf("\n\n\t\t\tSorting...\n");
	
	//Calling Function
	sort(x);
	
	//Display Data
	printf("\n\n===============================================================\n");
	printf("Here's your student that have been sorted by GPA then by NAME :\n");
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
	printf("NO\tNAME\t\t\tID\t\tGPA\t\tAge\n");
	printf("---------------------------------------------------------------\n\n");
	for(i=0; i < x; i++){
		printf("%d\t%s\t\t\t%lld\t\t%.2f\t\t%d\n",i+1, maha[i].name, maha[i].nim, maha[i].gpa, maha[i].age);
	} printf("\n\n\n"); return 0;
}
