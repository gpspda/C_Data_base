#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX 1024
//动态增长内存，满就申请内存 拷贝数据 释放内存  
//容量capacity	表示申请内存的最大空间 MAX
//size	记录当前数组具体元素的个数

typedef struct DynamicArry{
	int *pAddr;		//存放数据的地址
	int size;		//当前数组实际元素个数
	int capacity;	//容量，当前数组可承载最大数据个数
}Dynamic_Array;


//初始化
Dynamic_Array * Dynamic_Array_int();

//插入
void Push_Back_Array(Dynamic_Array *arr, int val);

//删除 根据位置
void RemoveByPos_Array(Dynamic_Array *arr, int pos);

//删除 根据值
void RemoveByVal_Array(Dynamic_Array *arr, int val);

//查找
int Find_Array(Dynamic_Array *arr, int val);

//释放动态数组内存
void FreeSpace_Array(Dynamic_Array *arr);

//清空数组
void Clear_Array(Dynamic_Array *arr);

//获得动态数组容量
int GetCapacity_Array(Dynamic_Array *arr);

//获得当前动态数组元素个数
int Size_Array(Dynamic_Array *arr);

//得到当前下标位置的数值
int At_Array(Dynamic_Array *arr, int n);

//打印
void Show_Array(Dynamic_Array *arr);


#endif