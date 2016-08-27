#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE{
	int val;
	struct NODE *lchild;
	struct NODE *rchild;
}Node;

typedef struct REST{
	int maxDepth;
	int maxDistence;
}REST;

int max(int a, int b){
	return a>b?a:b;
}

REST GetDistence(Node* root){
	if(root == NULL){
		REST empty = {0,-1};
		return empty;
	}

	REST lhs = GetDistence(root->lchild);
	REST rhs = GetDistence(root->rchild);

	REST ret;
	ret.maxDepth = max( lhs.maxDepth+1, rhs.maxDepth+1);
	ret.maxDistence = max( max( lhs.maxDistence, rhs.maxDistence) , rhs.maxDepth + lhs.maxDepth +2);

	return ret;
}

int main()
{
	printf("-----------------------\n");
	return 0;
}