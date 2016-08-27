#include "list.h"
#include "list_arr.c"

/*typedef struct DynamicArry{
	int *pAddr;		//存放数据的地址
	int size;		//当前数组实际元素个数
	int capacity;	//容量，当前数组可承载最大数据个数
}Dynamic_Array;*/


void test(){

	printf("\n\n---------------------------------------\n\n");
	Dynamic_Array  *parr = Dynamic_Array_int();
	//printf("Capacity:\t%d\n",GetCapacity_Array(parr));
	//printf("Size:\t%d\n",Size_Array(parr));
	
	int i;
	for(i =0; i<10; i++){
		Push_Back_Array(parr, i+1);
	}

	Show_Array(parr);
	
	RemoveByPos_Array(parr, 4);
	Show_Array(parr);

	printf("Find pos: %d\n", Find_Array(parr, 6));
	RemoveByVal_Array(parr, 8);
	//printf("Find pos: %d\n", Find_Array(parr, 6));
	Show_Array(parr);
	
	int pos = Find_Array(parr, 5);
	printf("Find pos: %d\t%d\n",pos, Find_Array(parr, 3));

	FreeSpace_Array(parr);
}

int main()
{
	test();
	//printf("Test\n");
	return 0;
}
