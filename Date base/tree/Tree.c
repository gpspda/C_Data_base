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

//����
StackList* Init_StackList(){
	StackList* lsatck = (StackList*)malloc(sizeof(StackList));
	if (lsatck == NULL)
		return NULL;
	lsatck->size = 0;
	lsatck->head.next = NULL;

	return lsatck;
}

//ջ��
StackNode* Top_StackList(StackList* lstack){
	if (lstack == NULL)
		return NULL;
	return lstack->head.next;
}

//��ջ
void Push_StackList(StackList* lsatck, StackNode* data){
	if (lsatck == NULL || data == NULL)
		return;

	data->next = lsatck->head.next;
	lsatck->head.next = data;

	lsatck->size++;
}

//��ջ
void Pop_StackList(StackList* lsatck){
	if (lsatck == NULL)
		return;
	if (lsatck->size == 0)
		return;

	StackNode* pDel = lsatck->head.next;
	lsatck->head.next = pDel->next;

	lsatck->size--;
}

//��ȡ��С
int Size_StackList(StackList* lsatck){
	if (lsatck == NULL)
		return 0;
	return lsatck->size;
}

//�ж�ջ��
int Empty(StackList* lsatck){
	if (lsatck->size == 0)
		return 1;
	return 0;
}

//����ջ
void Des_StackList(StackList* lsatck){
	while (!Empty(lsatck)){
		Pop_StackList(lsatck);
	}
	free(lsatck);
}

//----------------------�ǵݹ����������-------------
//���������
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
	//���ڵ����
	Push_StackList(stack, (StackNode*)Creat_Tree(root, MY_FALSE));

	while(Size_StackList(stack) > 0){
		//�ȵ���ջ���ڵ�
		BiTreeStackNode* node = (BiTreeStackNode*)Top_StackList(stack);
		Pop_StackList(stack);

		//�жϵ���ջ��Ԫ��
		if(node->root == NULL)
			continue;
		if(node->flag == MY_TRUE)
			printf("%c",node->root->ch);
		else{
			//��ǰ�ڵ���ջ

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
	//�������
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };


	//��������ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	//�������ǵݹ��ӡ
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