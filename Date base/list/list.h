#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX 1024
//��̬�����ڴ棬���������ڴ� �������� �ͷ��ڴ�  
//����capacity	��ʾ�����ڴ�����ռ� MAX
//size	��¼��ǰ�������Ԫ�صĸ���

typedef struct DynamicArry{
	int *pAddr;		//������ݵĵ�ַ
	int size;		//��ǰ����ʵ��Ԫ�ظ���
	int capacity;	//��������ǰ����ɳ���������ݸ���
}Dynamic_Array;


//��ʼ��
Dynamic_Array * Dynamic_Array_int();

//����
void Push_Back_Array(Dynamic_Array *arr, int val);

//ɾ�� ����λ��
void RemoveByPos_Array(Dynamic_Array *arr, int pos);

//ɾ�� ����ֵ
void RemoveByVal_Array(Dynamic_Array *arr, int val);

//����
int Find_Array(Dynamic_Array *arr, int val);

//�ͷŶ�̬�����ڴ�
void FreeSpace_Array(Dynamic_Array *arr);

//�������
void Clear_Array(Dynamic_Array *arr);

//��ö�̬��������
int GetCapacity_Array(Dynamic_Array *arr);

//��õ�ǰ��̬����Ԫ�ظ���
int Size_Array(Dynamic_Array *arr);

//�õ���ǰ�±�λ�õ���ֵ
int At_Array(Dynamic_Array *arr, int n);

//��ӡ
void Show_Array(Dynamic_Array *arr);


#endif