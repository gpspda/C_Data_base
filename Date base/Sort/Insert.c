#include "unp.h"


//½øµê²å¶ÓÅÅ¶Ó
void Insert(int *arr, int len){
	int i,j,tmp;

	for(j=1; j<len; j++){
		tmp =arr[j];
		/*i=j;
		while(i>0 && arr[i-1]>=tmp){
			arr[i]=arr[i-1];
			i--;
		}*/
		/*
		for(i =j-1; i>=0 && arr[i]>=tmp;i--)
			arr[i+1] = arr[i];
		*/
		for(i =j; i>0 && arr[i-1]>=tmp;i--)
			arr[i] = arr[i-1];
		arr[i]=tmp;
	}
}

void test(int *arr, int len){
	int j,i,tmp;
	for(j =1; j<len; j++){
		tmp = arr[j];
		for(i = j; i>0 &&arr[i-1] >=tmp; i--)
			arr[i] = arr[i-1];
		arr[i] =tmp;
	}
}

int main()
{
	int n =10;
	int arr[10] = {0};

	Create(arr, n);
	Show(arr,n);
	
//	Insert(arr, n);
	test(arr, n);

	Show(arr,n);


	return 0;
}