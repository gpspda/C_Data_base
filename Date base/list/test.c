#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QUEUENODE{
	struct QUEUENODE *next;
}QueueNode;

typedef struct QUEUELIST{
	QueueNode head;
	int size;
}QueueList;

typedef struct IOP{
	QueueNode node;
	char name[64];
	int age;
};


//初始化
QueueList *Init_QueueList(){
	QueueList *lq = (QueueList*)malloc(sizeof(QueueList));
	if (lq == NULL)
		return NULL;

	lq->head.next = NULL;
	lq->size = 0;
	
	return lq;
}

//销毁
void Destroy_QueueList(QueueList *lq){
	if (lq != NULL){
		free(lq);
		lq = NULL;
	}
}

//队尾插入元素
void Push_QueueList(QueueList *lq, QueueNode *data){
	if (lq == NULL || data == NULL)
		return;

	QueueNode *pCur = &lq->head;
	while (pCur!=NULL){
		pCur = pCur->next;
	}
	data->next = lq->head.next;
	lq->head.next = data;
	
	//printf("%x\t%x\n", lq->head.next,lq->head.next->next);

	lq->size++;
}

//弹出队头
void Pop_QueueList(QueueList *lq){
	if (lq == NULL)
		return;
	if (lq->size == 0)
		return;

	QueueNode *pDel = lq->head.next;
	lq->head.next = pDel->next;

	lq->size--;
}

//返回队头
QueueNode *Front_QueueList(QueueList *lq){
	if (lq == NULL)
		return NULL;
	return lq->head.next;
}

//返回队列长度
int Size_QueueList(QueueList *lq){
	if (lq == NULL)
		return 0;
	return lq->size;
}

//判断是否为空
int Empty_QueueList(QueueList *lq){
	if (lq->size == 0)
		return 1;
	return 0;
}


int main()
{
	QueueList *lq = Init_QueueList();

	IOP l1;
		IOP l2; 
		IOP l3;
		IOP l4;
		IOP l5;
	strcpy(l1.name, "aaa");
	strcpy(l2.name, "bbb");
	strcpy(l3.name, "ccc");
	strcpy(l4.name, "ddd");
	strcpy(l5.name, "eee");

	l1.age = 10;
	l2.age = 20;
	l3.age = 30;
	l4.age = 40;
	l5.age = 50; 

	Push_QueueList(lq, (QueueNode*)&l1);
	Push_QueueList(lq, (QueueNode*)&l2);
	Push_QueueList(lq, (QueueNode*)&l3);
	Push_QueueList(lq, (QueueNode*)&l4);
	Push_QueueList(lq, (QueueNode*)&l5);

	printf("Size:	%d\n", Size_QueueList(lq));

	while (Size_QueueList(lq) > 0){
		IOP *p = (IOP*)Front_QueueList(lq);
		printf("Name:%s\tAge:%d\n", p->name, p->age);
		Pop_QueueList(lq);
	}
	printf("Size:	%d\n", Size_QueueList(lq));

	system("pause");
	return 0;
}