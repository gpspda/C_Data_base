#include "link_list.h"
#include "link_list.c"

/*
int  Size_LinkList(LinkList *list);
void* Front_LinkList(LinkList *list);
int Find_LinkList(LinkList *list, void *val);
void Show_LinkList(LinkList *list, SHOW show);
void FreeSpace_LinkList(LinkList * list);
*/
typedef struct student{
	char name[64];
	int age;
	int scr;
}person;

void Show(void* data){
	person *p =(person*)data;
	printf("Name:%s\tAge:%d\tSrc:%d\t\n",p->name, p->age, p->scr);
}

void test(){
	//创建
	LinkList *list = Init_LinkList();
	
	person p1 = {"aaa",12,100};
	person p2 = {"bbb",11,180};
	person p3 = {"ccc",14,80};
	person p4 = {"ddd",17,10};
	person p5 = {"eee",27,110};

	Insert_LinkList(list,0, &p1);
	Insert_LinkList(list,0, &p2);
	Insert_LinkList(list,0, &p3);
	Insert_LinkList(list,0, &p4);
	Insert_LinkList(list,0, &p5);
	
	//打印
	printf("%d\n", Size_LinkList(list));
	Show_LinkList(list,Show);
	//删除
	printf("---------------------------\n");
	RemoveByPos_LinkList(list, 3);
	Show_LinkList(list,Show);

	//返回第一个节点
	printf("---------------------------\n");
	person *ret = (person*)Front_LinkList(list);
	printf("Name:%s\tAge:%d\tSrc:%d\t\n",ret->name, ret->age, ret->scr);
	
	printf("---------------------------\n");
	int p = Find_LinkList(list, "aaa");
	Show_LinkList(list,Show);
	FreeSpace_LinkList(list);


}

int main()
{
	test();
	printf("---------------------------\n");
	return 0;
}