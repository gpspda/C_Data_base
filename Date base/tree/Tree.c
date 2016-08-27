#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MY_FALSE 0
#define MY_TRUE 1

typedef struct STACKNODE{
	struct STACKNODE *next;
}StackNode;

typedef struct STACKLIST{
	StackNode head;
	int size;
}StackList;

//创建
StackList* Init_StackList(){
	StackList* lsatck = (StackList*)malloc(sizeof(StackList));
	if (lsatck == NULL)
		return NULL;
	lsatck->size = 0;
	lsatck->head.next = NULL;

	return lsatck;
}

//栈顶
StackNode* Top_StackList(StackList* lstack){
	if (lstack == NULL)
		return NULL;
	return lstack->head.next;
}

//入栈
void Push_StackList(StackList* lsatck, StackNode* data){
	if (lsatck == NULL || data == NULL)
		return;

	data->next = lsatck->head.next;
	lsatck->head.next = data;

	lsatck->size++;
}

//出栈
void Pop_StackList(StackList* lsatck){
	if (lsatck == NULL)
		return;
	if (lsatck->size == 0)
		return;

	StackNode* pDel = lsatck->head.next;
	lsatck->head.next = pDel->next;

	lsatck->size--;
}

//获取大小
int Size_StackList(StackList* lsatck){
	if (lsatck == NULL)
		return 0;
	return lsatck->size;
}

//判断栈空
int Empty(StackList* lsatck){
	if (lsatck->size == 0)
		return 1;
	return 0;
}

//销毁栈
void Des_StackList(StackList* lsatck){
	while (!Empty(lsatck)){
		Pop_StackList(lsatck);
	}
	free(lsatck);
}

//----------------------非递归遍历二叉树-------------
//二叉树结点
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

typedef struct BITREESTACKNODE{
	StackNode node;
	BinaryNode* root;
	int flag;
}BiTreeStackNode;


BiTreeStackNode* Creat_Tree(BinaryNode *node, int flag){
	BiTreeStackNode* tree = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	tree->root = node;
	tree->flag = flag;
	return tree;
}

BinaryNode* Create_Tree(){

	BinaryNode* root;
	fflush(stdin);
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	else{
		root = (BinaryNode*)malloc(sizeof(BinaryNode));
		root->ch = ch;
		root->lchild = Create_Tree();
		root->rchild = Create_Tree();
	}
	return root;
}

void NonRecursion(BinaryNode *root){
	StackList* stack = Init_StackList();
	//根节点入队
	Push_StackList(stack, (StackNode*)Creat_Tree(root, MY_FALSE));

	while(Size_StackList(stack) > 0){
		//先弹出栈顶节点
		BiTreeStackNode* node = (BiTreeStackNode*)Top_StackList(stack);
		Pop_StackList(stack);

		//判断弹出栈顶元素
		if(node->root == NULL)
			continue;
		if(node->flag == MY_TRUE)
			printf("%c",node->root->ch);
		else{
			//当前节点入栈

			node->flag = MY_TRUE;
			Push_StackList(stack,(StackNode*)node);
			Push_StackList(stack, (StackNode*)Creat_Tree(node->root->rchild, MY_FALSE));
			Push_StackList(stack, (StackNode*)Creat_Tree(node->root->lchild, MY_FALSE));
		}
	}
}




void Recursion(BinaryNode *root){
	if (root == NULL)
		return;

	printf("%c", root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}

void test__tree(){
	//创建结点
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };


	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	//二叉树非递归打印
	NonRecursion(&node1); printf("\n");
	Recursion(&node1); printf("\n");
}

int main()
{
	test__tree();
	printf("\n------------------------------------------------------\n");
	system("pause");
	return 0;
}