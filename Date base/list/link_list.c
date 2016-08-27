#include "link_list.h"


//��ʼ������
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

//ָ��λ�ò���
void Insert_LinkList(LinkList *list, int pos, void*val){
	if(list == NULL || val ==NULL)
		return ;

	if(pos < 0 || pos > list->size)
		pos = list->size ;

	
	int i;
	
	//�����½ڵ�
	LinkNode *newN = (LinkNode*)malloc(sizeof(LinkNode));
	newN->data = val;
	newN->next = NULL;
	

	//��ָ��----->��������ָ��
	LinkNode *pCur = list->head;
	for(i =0; i<pos; i++)
		pCur = pCur->next;

	//�½ֵ�������
	newN->next = pCur->next;
	pCur->next = newN;

	list->size++;
 }

 //ɾ��ָ��Ϊֵ
void RemoveByPos_LinkList(LinkList *list, int pos){
	if(list == NULL)
		return ;
	if(pos < 0 || pos >= list->size){
		printf("Error pos\n");
		exit(0);
	}
	//����ɾ���ڵ��ǰһ���ڵ�
	int i;
	LinkNode *pCur = list->head;
	for(i =0; i<pos; i++)
		pCur = pCur->next;
	//����ɾ���Ľڵ�
	LinkNode *pDel = pCur->next;
	pCur->next = pDel->next;
	//�ͷŽڵ��ڴ�
	free(pDel);

	list->size--;
}

//������
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

//���ص�һ���ڵ�
void* Front_LinkList(LinkList *list){
	if(list == NULL)
		return NULL;
	return list->head->next->data;
}

//����ֵ
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

//��ӡ
void Show_LinkList(LinkList *list, SHOW show){
	if(list == NULL)
		return;
	
	//����ָ�����
	LinkNode *pCur = list->head->next;
	while(pCur != NULL){
		show(pCur->data);
		pCur=pCur->next;
	}
}

//�ͷ�
void FreeSpace_LinkList(LinkList * list){
	if(list == NULL)
		return ;

	//����ָ�����
	LinkNode *pCur = list->head;
	while(pCur != NULL){
		//������һ���ڵ�
		LinkNode *pNext = pCur->next;
		free(pCur);
		pCur = pNext;
	}
	
	//�ͷ������ڴ�
	list->size = 0;
	free(list);
}
