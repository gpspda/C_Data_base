#include "link_list.h"


//初始化链表
LinkList * Init_LinkList(){
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));
	if(list == NULL)
		return NULL;
	list->head = (LinkNode *)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	list->size = 0;
	return list;
}

//指定位置插入
void Insert_LinkList(LinkList *list, int pos, void*val){
	if(list == NULL || val ==NULL)
		return ;

	if(pos < 0 || pos > list->size)
		pos = list->size ;

	
	int i;
	
	//创建新节点
	LinkNode *newN = (LinkNode*)malloc(sizeof(LinkNode));
	newN->data = val;
	newN->next = NULL;
	

	//找指针----->辅助变量指针
	LinkNode *pCur = list->head;
	for(i =0; i<pos; i++)
		pCur = pCur->next;

	//新街点入链表
	newN->next = pCur->next;
	pCur->next = newN;

	list->size++;
 }

 //删除指定为值
void RemoveByPos_LinkList(LinkList *list, int pos){
	if(list == NULL)
		return ;
	if(pos < 0 || pos >= list->size){
		printf("Error pos\n");
		exit(0);
	}
	//查找删除节点的前一个节点
	int i;
	LinkNode *pCur = list->head;
	for(i =0; i<pos; i++)
		pCur = pCur->next;
	//缓存删除的节点
	LinkNode *pDel = pCur->next;
	pCur->next = pDel->next;
	//释放节点内存
	free(pDel);

	list->size--;
}

//链表长度
int  Size_LinkList(LinkList *list){
	/*if(list == NULL)
		return 0;

	int i =0;
	LinkList *p =list;
	while(p->head->next != NULL){
		i++;
		p->head = p->head->next;
	}
	return i;*/

	return list->size;
}

//返回第一个节点
void* Front_LinkList(LinkList *list){
	if(list == NULL)
		return NULL;
	return list->head->next->data;
}

//查找值
int Find_LinkList(LinkList *list, void *val){
	if(list == NULL)
		return -1;
	
	int i=0;
	LinkNode *pCur = list->head->next; 
	while(pCur != NULL){
		i++;
		if(pCur->data == val){
			return i;
		}
		pCur=pCur->next;
	}
	return -2;
}

//打印
void Show_LinkList(LinkList *list, SHOW show){
	if(list == NULL)
		return;
	
	//辅助指针变量
	LinkNode *pCur = list->head->next;
	while(pCur != NULL){
		show(pCur->data);
		pCur=pCur->next;
	}
}

//释放
void FreeSpace_LinkList(LinkList * list){
	if(list == NULL)
		return ;

	//辅助指针变量
	LinkNode *pCur = list->head;
	while(pCur != NULL){
		//缓存下一个节点
		LinkNode *pNext = pCur->next;
		free(pCur);
		pCur = pNext;
	}
	
	//释放链表内存
	list->size = 0;
	free(list);
}
