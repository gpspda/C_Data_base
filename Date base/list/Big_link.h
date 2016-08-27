#ifndef _BIG_LINK_H_
#define _BIG_LINK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINKNODE{
	struct LINKNODE *next;
}LinkNode;

typedef struct LINKLIST{
	LinkNode head;
	int size;
}LinkList;

//��ӡ�����Ļص�ָ��
typedef void(*SHOW)(LinkNode*);
//�ȽϺ���ָ��
typedef int(*COMPARENODE)(LinkNode *,LinkNode *);

//��ʼ������
LinkList * Init_LinkList();

//ָ��λ�ò���
void Insert_LinkList(LinkList *list, int pos, LinkNode *data);

//ɾ��ָ��Ϊֵ
void RemoveByPos_LinkList(LinkList *list, int pos);

//������
int  Size_LinkList(LinkList *list);

//����ֵ
int Find_LinkList(LinkList *list, LinkNode *data, COMPARENODE compare);

//��ӡ
void Show_LinkList(LinkList *list, SHOW show);

//�ͷ�
void FreeSpace_LinkList(LinkList * list);


#endif