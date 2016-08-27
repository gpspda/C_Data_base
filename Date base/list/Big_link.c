#include "Big_link.h"

LinkList * Init_LinkList(){
	LinkList *list =(LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size =0;
	return list;
}

//指定位置插入
void Insert_LinkList(LinkList *list, int pos, LinkNode *data){
	if(list == NULL || data ==NULL)
		return ;
	if(pos < 0 || pos > list->size)
		pos=list->size;
	//查找插入位置
	LinkNode *pCur = &(list->head);
	int i;
	//for(i =0 ; i<list->size;i++)
	for(i=0; i<pos;i++)
		pCur =pCur->next;

	data->next = pCur->next;
	pCur->next = data;

	list->size++;
}

//删除指定为值
void RemoveByPos_LinkList(LinkList *list, int pos){
	if(list == NULL )
		return ;
	if(pos < 0 || pos >list->size)
		return ;

	LinkNode * pCur = &(list->head);
	int i;
	for(i =0 ; i<pos; i++)
		pCur = pCur->next;

	pCur->next = pCur->next->next;

	list->size--;
}

//链表长度
int  Size_LinkList(LinkList *list){
	if(list == NULL)
		return 0;
	return list->size;
}

//查找值
int  Find_LinkList(LinkList *list, LinkNode *data, COMPARENODE compare){
	if(list == NULL || data == NULL)
		return -1;

	LinkNode *pCur = list->head.next;
	int index=0;
	while(pCur != NULL){
		if(compare(pCur, data) == 0)
			return index;
		pCur=pCur->next;
		index++;
	}
	return -2;
}

//打印
void Show_LinkList(LinkList *list, SHOW show){
	if(list == NULL)
		return ;
	LinkNode *pCur =list->head.next;
	while(pCur!=NULL){
		show(pCur);
		pCur=pCur->next;
	}
}

//释放
void FreeSpace_LinkList(LinkList * list){
	if(list!=NULL){
		free(list);
	}
}


//--------------------------------------------------------------------------

typedef struct Person{
	LinkNode node;
	char name[64];
	int age;
}person;

void Print(LinkNode *p){
	person *da=(person *)p;
	printf("Name:%s\tAge:%d\n",da->name,da->age);
}

int MyCompare(LinkNode *node1,LinkNode *node2){
	person *p1 =(person*)node1;
	person *p2 =(person*)node2;

	if(strcmp(p1->name,p2->name) == 0 && p1->age == p2->age)
		return 0;
	return -1;
}


void test(){
	LinkList *list = Init_LinkList();

	person p1,p2,p3,p4,p5;

	strcpy(p1.name,"aaa");
	strcpy(p2.name,"bbb");
	strcpy(p3.name,"ccc");
	strcpy(p4.name,"ddd");
	strcpy(p5.name,"eee");

	p1.age =10;
	p2.age =20;
	p3.age =30;
	p4.age =40;
	p5.age =50;

	Insert_LinkList(list,0, (LinkNode*)&p1);
	Insert_LinkList(list,0, (LinkNode*)&p2);
	Insert_LinkList(list,0, (LinkNode*)&p3);
	Insert_LinkList(list,0, (LinkNode*)&p4);
	Insert_LinkList(list,0, (LinkNode*)&p5);

	Show_LinkList(list,Print);

	printf("----------------------------\n");
	RemoveByPos_LinkList(list, 2);
	Show_LinkList(list,Print);

	printf("----------------------------\n");
	person find;
	strcpy(find.name,"bbb");
	find.age = 20;
	int pos = Find_LinkList(list,(LinkNode*)&find,MyCompare);
	printf("pos:%d\n",pos);

	FreeSpace_LinkList(list);
}

int main()
{
	test();
	printf("----------------------------\n");
	return 0;
}