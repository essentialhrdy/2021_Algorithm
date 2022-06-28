#include "p1_solution.h"

void insertion_sort (int arr[], int len)
{
	printf("Insertion\n");

	int i,j,key;

    for(i=1; i<len; i++){
    	key = arr[i]; 
    	for(j=i-1; j>=0 && arr[j]<key; j--){
      		arr[j+1] = arr[j];
    	}
		arr[j+1] = key;
		//출력부분
		for(int k=0; k<len; k++){
            std::cout << arr[k];
            printf(" ");
        }
        printf("\n");
    
  }

		
}

	

void bubble_sort (int arr[], int len)
{	
	printf("Bubble\n");

	for(int i=len-1; i>=0; i--){
		for(int j=0; j<i; j++)
			if(arr[j] < arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		//출력부분
		for(int k=0; k<len; k++){
            std::cout << arr[k];
            printf(" ");
        }
        printf("\n");
	}

	

}
