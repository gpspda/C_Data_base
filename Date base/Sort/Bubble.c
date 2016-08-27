#include "unp.h"

void Bubble(int *arr, int len){
	int i,j;
	int flag = 1;

	for(i=0; i<len && flag ==1; i++){
		flag =0;
		for(j =len-1; j>i; j--){
			if(arr[j-1] > arr[j]){
				flag =1;
				swap(&arr[j-1], &arr[j]);
			}
		}
	}
}

void test(int *arr, int len){
	int flag =1;
	int i,j;
	for(i=0; i<len && flag == 1; i++){
		flag = 0;
		for(j=len-1; j>i; j--){
			if(arr[j-1] > arr[j]){
				swap(&arr[j-1], &arr[j]);
				flag =1;
			}
		}
	}
}

int main()
{
	int n=10;
	int arr[10]={0};
	Create(arr, n);
	Show(arr, n);

//	Bubble(arr, n);
	test(arr, n);

	Show(arr ,n);

	return 0;
}