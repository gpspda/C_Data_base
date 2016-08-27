#include "unp.h"

#define Lch(i) (2*i+1)
void Heap_sort(int *arr, int index, int len){
	int max = index;
	int lchild = Lch(index);
	int rchild = Lch(index)+1;

	if(lchild < len && arr[max] < arr[lchild])
		max = lchild;
	if(rchild < len && arr[max] < arr[rchild])
		max = rchild;
 
	if(index != max){
		swap(&arr[index], &arr[max]);
		Heap_sort(arr, max, len);
	}
}

void Heap(int arr[], int len){ 
	int i;
	for(i = len/2 -1; i >=0 ;i--)
		Heap_sort(arr, i, len);
	for(i = len -1; i>=0; i--){
		swap(&arr[0],&arr[i]);
		Heap_sort(arr, 0, i);
	}
}

void test_sort(int *arr, int index, int len){
	int max = index;
	int lchild = 2*index+1;
	int rchild = 2*index+2;

	if(lchild<len && arr[max]<arr[lchild])
		max = lchild;
	if(rchild<len && arr[max]<arr[rchild])
		max = rchild;

	if(index!=max){
		swap(&arr[index], &arr[max]);
		test_sort(arr, max, len);
	}
}

void test(int *arr, int len){
	int i;
	for(i =len/2-1; i>=0; i--)
		test_sort(arr,i,len);
	for(i = len-1; i>=0; i--){
		swap(&arr[0],&arr[i]);
		test_sort(arr, 0, i);
	}
}

int main()
{
	int n =10;
	int arr[10] = {0};

	Create(arr, n);
	Show(arr,n);

	test(arr,n);
	Show(arr,n);
	return 0;
}