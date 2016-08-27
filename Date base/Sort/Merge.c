#include "unp.h"

void Merge_Two_sort(int *soc, int *des, int left, int mind, int right){
	int low = left;
	int mid = mind +1;
	int k = left;

	while((low<=mind)&&(mid<=right)){
		if(soc[low] < soc[mid])	
			des[k++] = soc[low++];
		else
			des[k++] = soc[mid++];
	}

	while(low <= mind)
		des[k++] = soc[low++];
	while(mid <= right)
		des[k++] = soc[mid++];
}

void Merge_sort(int *soc, int *des, int left, int right, int max){
	if(left == right)
		des[left] = soc[left];
	else{
		int mid = (left + right)/2;
		int *space = (int *)malloc(sizeof(int)*max);
		if(space != NULL){
			Merge_sort(soc, space, left, mid, max);
			Merge_sort(soc, space, mid+1, right, max);
			Merge_Two_sort(space, des, left, mid, right);
		}
		free(space);
	}
}

void Merge(int *arr, int len){
	Merge_sort(arr, arr, 0, len-1, len);
}

void test_two_sort(int *soc, int*des, int left, int mind , int right){
	int low = left;
	int mid = mind +1;
	int k =left;

	while( low <= mind && mid<=right ){
		if(soc[low] < soc[mid])
			des[k++] = soc[low++];
		else
			des[k++] = soc[mid++];
	}
	while( low <=mind )
		des[k++] = soc[low++];
	while( mid <= right)
		des[k++] = soc[mid++];
}

void test_sort(int *soc, int *des, int left, int right, int max){
	if(left == right)
		des[left] = soc[left];
	else{
		int mid = (left + right)/2;
		int *space = (int *)malloc(sizeof(int)*max);
		if(space!=NULL){
			test_sort(soc, space, left, mid, max);
			test_sort(soc, space, mid+1, right, max);
			test_two_sort(space, des, left, mid, right);
		}
		free(space);
	}
}

void test(int *arr, int len){
	test_sort(arr, arr, 0, len-1, len);
}
 
int main()
{
	int n =10;
	int arr[10] = {0};

	Create(arr, n);
	Show(arr,n);

	Merge(arr, n);
	Show(arr, n);

	
	Create(arr, n);
	Show(arr,n);

	test(arr, n);
	Show(arr, n);

	return 0;
}
