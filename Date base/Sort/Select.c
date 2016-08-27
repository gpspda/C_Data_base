#include "unp.h"

void Select(int *arr, int len){
	int i,j;
	for(i = 0; i<len ; i++){
		for(j =i+1; j<len; j++){
			if(arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

void test(int *arr, int len){
	int i,j;
	for(i=0; i<len; i++){
		for(j =i+1; j<len; j++){
			if(arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

int main()
{
	int n =10;
	int arr[10] = {0};

	Create(arr, n);
	Show(arr,n);
	
	Select(arr, n);
	Show(arr,n);

	return 0;
}