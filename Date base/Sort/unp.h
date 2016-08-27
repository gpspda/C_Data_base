#ifndef __UNO_H__
#define __UNO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

void Create( int *arr, int n){
	int i;
	srand((unsigned int)time(NULL));

	for(i=0; i<n; i++){
		arr[i] = rand()%100;
	}
}

void Show(int *arr, int len){
	int i=0;
	for(i =0; i<len; i++){
		printf("%d  ",arr[i]);
	}
	printf("\n---------------------------------------------\n");
}

void swap(int* a, int* b){
	int  c;
	c = *a;
	*a = *b;
	*b =c;
}

/*
int main()
{
	int n;
	while(scanf("%d",&n) != EOF))
	{
		int *arr = (int *)malloc(sizeof(int)*n);
		Cretae(arr, n);
		Show(arr,n);
	}
	return 0;
}

*/


#endif