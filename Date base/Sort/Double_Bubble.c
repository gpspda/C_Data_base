#include "unp.h"

void Double_Bubble(int *arr, int len){
	int i;
	int low, high;
	low =-1;
	high = len;

	while(low < high){
		for(i = low+1 ;(i<high) && ((i+1)<high); i++){
			if(arr[i]>arr[i+1])
				swap(&arr[i], &arr[i+1]);
		}
		high--;

		for(i = high -1; (i>low) && (i-1 > low ); i--){
			if(arr[i] < arr[i-1])
				swap(&arr[i], &arr[i-1]);
		}
		low++;
	}
}

void test(int *arr, int len){
	int i;
	int low, high;
	low = -1;
	high = len;
	while(low < high){
		for(i=low+1; (i<high) && ((i+1)<high); i++ ){
			if(arr[i]>arr[i+1])
				swap(&arr[i], &arr[i+1]);
		}
		high--;
		for(i =high-1; (i>low) && ((i-1)>low); i--){
			if(arr[i]<arr[i-1])
				swap(&arr[i], &arr[i-1]);
		}
		low++;
	}
}

int main()
{
	int n =10;
	int arr[10] = {0};

	Create(arr, n);
	Show(arr,n);
	
//	Double_Bubble(arr, n);
	test(arr, n);

	Show(arr,n);

	return 0;
}