#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACKNODE{
	void *data[256];
	int size;
}Stack;

//初始化
Stack * Init_Stack(){
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL)
		return NULL;

	stack->size = 0;
	int i;
	for(i =0; i<256; i++){
		stack->data[i] = 0;
	}
	return stack;
}

//入栈
void Push_Stack(Stack *stack, void *data){
	if(stack->size == 256)
		return ;
	if(stack == NULL)
		return ;
	stack->data[stack->size]=data;
	stack->size++;
}

//出栈
void Pop_Stack(Stack *stack){
	if(stack==NULL)
		return ;
	if(stack->size == 0)
		return ;
	stack->data[stack->size-1] = 0;
	stack->size--;
}

//栈顶
void *Top_Stack(Stack *stack){
	if(stack == NULL)
		return NULL;
	if(stack->size==0)
		return NULL;
	return stack->data[stack->size-1];
}

//销毁
void Destroy_Stack(Stack *stack){
	if(stack!=NULL){
		free(stack);
		stack=NULL;
	}
}

//栈空
int Empty_Stack(Stack *stack){
	if(stack->size == 0)
		return 1;
	return 0;
}


//清空
void Clear_Stack(Stack *stack){
	if(stack == NULL)
		return ;
	int i;
	for(i =0 ;i<stack->size; i++){
		stack->data[i] = NULL;
	}
	stack->size =0;
}

//元素个数
int Size_Stack(Stack *stack ){
	if(stack == NULL)
		return 0;
	return stack->size;
}

typedef struct Person{
	char name[64];
	int age;
}person;

int main()
{
	Stack * stack = Init_Stack();
	person p1={"aaa",10};
	person p2={"bbb",20};
	person p3={"ccc",40};

	Push_Stack(stack,&p1);
	Push_Stack(stack,&p2);
	Push_Stack(stack,&p3);

	while(stack->size >0){
		person *p = (person*)Top_Stack(stack);
		printf("Name:%s\tAge:\t%d\n",p->name,p->age);
		Pop_Stack(stack);
	}

	Destroy_Stack(stack);

	printf("-------------------\n");
	return 0;
}