#include "unp.h"


//-------------------------1--------------------------
void Quick(int *arr, int left, int right){
	if(left < right){
		int key = arr[left];

		int low = left;
		int high = right;

		while(low < high){

			while(low < high && arr[high] >= key)
				high--;
			arr[low] = arr[high];

			while(low < high && arr[low] <= key)
				low++;
			arr[high] = arr[low];

		}
		arr[low] = key;
		Quick(arr, left, low-1);
		Quick(arr, low+1, right);
	}
}

void test(int *arr, int left, int right){
	if(left < right){
		int key =arr[left];

		int low = left;
		int high = right;

		while(low < high){
			while( low <high && arr[high] >=key )
				high--;
			arr[low] = arr[high];

			while(low <high && arr[low]<=key)
				low++;
			arr[high]=arr[low];
		}
		arr[low] = key;

		test(arr, left, low-1);
		test(arr, low+1, right);
	}
}

//--------------2-------------------------------
void Quick_mid(int *arr, int left, int right){
	int low = left;
	int high = right;

	int key = arr[(left+right)/2];

	while(low <= high){

		while(arr[low] < key)
			low++;

		while(arr[high] > key)
			high--;

		if(low <= high){
			swap(&arr[low], &arr[high]);

			low++;
			high--;
		}
	}
	
	if(left < high)
		//Quick_mid(arr, left, low-1);
		Quick_mid(arr, left, high);
	if(low < right)
		//Quick_mid(arr, high+1, right);
		Quick_mid(arr, low, right);

}

int main()
{
	int n =10;
	int arr[10] = {0};

	Create(arr, n);
	Show(arr,n);

	Quick_mid(arr,0,n-1);
	Show(arr,n);

	int data[16]={1000,0,6,8,7,3,2,1,7,156,44,23,123,11,5};
	Show(data,16);

	test(data,0,15);
	Show(data,16);

	/*Create(arr, n);
	Show(arr,n);
	test(arr,0,n-1);
	Show(arr,n);*/
	return 0;
}