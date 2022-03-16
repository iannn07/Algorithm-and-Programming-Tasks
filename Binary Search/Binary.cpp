#include<stdio.h>
#include<stdlib.h>
int search(int arr[], int x, int low, int high){
    if(high >= low){
        int mid = (low+high) / 2;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) return search(arr, x, mid+1, high);

        return search(arr, x, low, mid-1);
    } return -1;
}
int main(){
    int arr[] = {12, 23, 39, 57, 66, 68, 75, 90, 98};
    int size = sizeof(arr)/sizeof(*arr);
	int x, final, temp;
    scanf("%d", &x, printf("Cari no brp bang? "));
    for(int i=0; i < size - 1; i++){
		for(int j=i+1; j < size; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;	
			}
		}
	}
    
    final = search(arr, x, 0, size - 1);
	
    if(final == -1) printf("Takde ni bang\n");
	
    else printf("Adeee nih bang di index %d\n", final);
}   
