#include "unp.h"


void Insert(int *arr, int n){
	int i,j;
	int tmp;

	for(j =1; j < n; j++){
		tmp =arr[j];
		for(i =j; i>0 && arr[i-1] >= tmp; i--)
			arr[i]=arr[i-1];
		arr[i]=tmp;
	}
}


void Shell(int *arr, int n){
	int i,j;
	int tmp;
	int gap =n;

	do{
		gap = gap/3+1;
		/*for(j =gap; j < n; j++){
			tmp =arr[j];
			for(i =j-gap; (i>=0) && (arr[i] > tmp); i-=gap)
				arr[i+gap]=arr[i];
			arr[i+gap]=tmp;
		}*/
		for(j =gap; j < n; j+=gap){
			tmp =arr[j];
			for(i =j-gap; (i>=0) && (arr[i] > tmp); i-=gap)
				arr[i+gap]=arr[i];
			arr[i+gap]=tmp;
		}

	}while(gap >1);
}

void test(int *arr, int len){
	int i,j;
	int tmp;
	int gap =len;

	do{
		gap =gap/3+1;
		
		for(j = gap; j<len; j+=gap){
			tmp = arr[j];
			for(i = j-gap; i>=0 && arr[i] > tmp; i-=gap)
				arr[i+gap] = arr[i];
			arr[i+gap] = tmp;
		}

	}while(gap>1);
}

int main()
{
	int n =10;
	int arr[10] = {0};


	Create(arr, n);
	Show(arr,n);

	Insert(arr, n);
	Show(arr, n);
printf("####################################################\n");
	Create(arr, n);
	Show(arr,n);

	test(arr, n);
	Show(arr, n);

	return 0;
}