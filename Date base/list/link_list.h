#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ڵ�
typedef struct LINKNODE{
	void* data;						//ָ���κ��������͵�����
	struct LINKNODE *next;
}LinkNode, *Node;

//����ṹ��
typedef struct LINKLIST{
	LinkNode* head;				//ͷ���
	int size;
}LinkList;

//��ӡ�����Ļص�ָ��
typedef void(*SHOW)(void*);

//��ʼ������
LinkList * Init_LinkList();

//ָ��λ�ò���
 void Insert_LinkList(LinkList *list, int pos, void*val);

 //ɾ��ָ��Ϊֵ
 void RemoveByPos_LinkList(LinkList *list, int pos);

//������
int  Size_LinkList(LinkList *list);

//���ص�һ���ڵ�
void* Front_LinkList(LinkList *list);

//����ֵ
int Find_LinkList(LinkList *list, void *val);

//��ӡ
void Show_LinkList(LinkList *list, SHOW show);

//�ͷ�
void FreeSpace_LinkList(LinkList * list);

#endif