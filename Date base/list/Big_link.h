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

//打印函数的回调指针
typedef void(*SHOW)(LinkNode*);
//比较函数指针
typedef int(*COMPARENODE)(LinkNode *,LinkNode *);

//初始化链表
LinkList * Init_LinkList();

//指定位置插入
void Insert_LinkList(LinkList *list, int pos, LinkNode *data);

//删除指定为值
void RemoveByPos_LinkList(LinkList *list, int pos);

//链表长度
int  Size_LinkList(LinkList *list);

//查找值
int Find_LinkList(LinkList *list, LinkNode *data, COMPARENODE compare);

//打印
void Show_LinkList(LinkList *list, SHOW show);

//释放
void FreeSpace_LinkList(LinkList * list);


#endif