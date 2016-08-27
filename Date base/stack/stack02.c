#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACKNODE{
	struct STACKNODE *next;
}StackNode;

typedef struct STACKLIST{
	StackNode head;
	int size;
}StackList;

typedef struct YOUP{
	StackNode node;
	char name[64];
	int age;
}YouP;

//创建
StackList* Init_StackList(){
	StackList* lsatck = (StackList*)malloc(sizeof(StackList));
	if(lsatck == NULL)
		return NULL;
	lsatck->size=0;
	lsatck->head.next = NULL;

	return lsatck;
}

//栈顶
StackNode* Top_StackList(StackList* lstack){
	if(lstack == NULL)
		return NULL;
	return lstack->head.next;
}

//入栈
void Push_StackList(StackList* lsatck , StackNode* data){
	if(lsatck == NULL || data == NULL)
		return ;

	data->next = lsatck->head.next;
	lsatck->head.next = data;

	lsatck->size++;
}

//出栈
void Pop_StackList(StackList* lsatck){
	if(lsatck == NULL)
		return ;
	if(lsatck->size == 0)
		return;

	StackNode* pDel = lsatck->head.next;
	lsatck->head.next = pDel->next;

	lsatck->size--;
}

//获取大小
int Size_StackList(StackList* lsatck){
	if(lsatck == NULL)
		return 0;
	return lsatck->size;
}

//判断栈空
int Empty(StackList* lsatck){
	if(lsatck->size == 0)
		return 1;
	return 0;
}

//销毁栈
void Des_StackList(StackList* lsatck){
	while(!Empty(lsatck)){
		Pop_StackList(lsatck);
	}
	free(lsatck);
}


//--------------------------------------------------------------------
void test01(){
	
	StackList *lstack = Init_StackList();

	YouP p1, p2, p3, p4;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");

	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;

	Push_StackList(lstack, (StackNode*)&p1);
	Push_StackList(lstack, (StackNode*)&p2);
	Push_StackList(lstack, (StackNode*)&p3);
	Push_StackList(lstack, (StackNode*)&p4);

	while (Size_StackList(lstack) > 0){
		YouP *p = (YouP*)Top_StackList(lstack);
		printf("Name:\t%sAge:\t%d\n", p->name, p->age);
		Pop_StackList(lstack);
	}

	Des_StackList(lstack);
}

//--------------------------括号匹配-------------------------------------

typedef struct MYCHAR{
	StackNode node;
	char *pAd;
	int index;
}MyChar;

MyChar* Create(char*p, int n){
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->pAd =p;
	mychar->index = n;
	return mychar;
}

void ShowError(char *p, int pos){
	int i;
	printf("%s\n",p);
	for(i=0; i<pos;i++){
		printf(" ");
	}
	printf("A");
}

void test02(){
	char *str =  "1+8+5)+6+9+8*(asfdj--+asfjb-(568)*4-8)*(--)-__(__---";
	char *p=str;

	StackList *stack = Init_StackList();
	
	int index =0;
	while(*p!='\0'){
		switch(*p){
			//左括号直接进栈
			case '(':Push_StackList(stack, (StackNode*)Create(p,index)); break;
			//如果是右括号 从栈顶弹出 判断是不是左括号
			case ')':
				if(Size_StackList(stack) > 0){
					MyChar* mychar = (MyChar*)Top_StackList(stack);
					if(*mychar->pAd == '('){
						Pop_StackList(stack);
						free(mychar);
					}
				}else{
					printf("右括号没有匹配的左括号：\n");
					ShowError(str, index);
					printf("\n");
				}
				break;

			default:break;
		}
		p++;
		index++;
	}

	while(Size_StackList(stack) > 0){
		MyChar* mychar = (MyChar*)Top_StackList(stack);
		printf("左括号没有匹配的右括号：\n");
		ShowError(str,mychar->index);
		Pop_StackList(stack);
		free(mychar);
	}
	Des_StackList(stack);
}

//-------------------------中缀-----转------后缀-----------------------
//8+(3-1)*5------------------------>831-5*+
/*		
遍历中缀表达式中的数字和符号：
 对于数字：直接输出
 对于符号：
 左括号：进栈
 运算符号：与栈顶符号进行优先级比较
 若栈顶符号优先级低：此符号进栈
（默认栈顶若是左括号，左括号优先级最低）
 若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
 右括号：将栈顶符号弹出并输出，直到匹配左括号
遍历结束：将栈中的所有符号弹出并输出
*/

typedef struct MYNWECHAR{
	StackNode node;
	char *pAd;
}MyNewChar;

MyNewChar* Creat(char *p){
	MyNewChar* mychar = (MyNewChar*)malloc(sizeof(MyNewChar));
	if(mychar == NULL)
		return NULL;
	mychar->pAd = p;
	return mychar;
}

int GetPrior(char c){
	if( c == '/' || c == '*' || c == '%')
		return 2;
	if(c == '+' || c == '-')
		return 1;
	return 0;
}

void test03(){
	char *str = "8+(3-1)*5";
	char *p = str;
	
	StackList* stack = Init_StackList();

	while(*p!='\0'){
		switch(*p){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':printf("%c",*p); break;

			case '(':Push_StackList(stack,(StackNode*)Creat(p)); break;
			case ')':
				while(Size_StackList(stack) > 0){
					MyNewChar* mychar = (MyNewChar*)Top_StackList(stack);
					if(*(mychar->pAd) == '('){
						Pop_StackList(stack);
						free(mychar);
						break;
					}
					printf("%c",*mychar->pAd);
					Pop_StackList(stack);
					free(mychar);
				}
				break;
			//如果是运算符则与栈顶符号进行优先级比较
			//若栈顶符号优先级低：	此符号进栈（默认栈顶若是左括号，左括号优先级最低）
			//若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':{
				MyNewChar* mychar = (MyNewChar* )Top_StackList(stack);
				if(mychar == NULL){
					Push_StackList(stack,(StackNode*)Creat(p));
					break;
				}
				//如果栈顶优先级低于当前字符的优先级 直接入栈
				if(GetPrior(*p) > GetPrior(*(mychar->pAd))){
					Push_StackList(stack,(StackNode*)Creat(p));
				}
				//若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
				else{
					while(Size_StackList(stack) > 0){
						MyNewChar* mc = (MyNewChar*)malloc(sizeof(MyNewChar));

						if(GetPrior(*p) > GetPrior(*(mc->pAd))){
							Push_StackList(stack,(StackNode*)Creat(p));
							break;
						}

						printf("%c",*mc->pAd);
						Pop_StackList(stack);
						free(mc);
					}
				}
			}
			break;
			default:printf("Error\n");break;
		}
		p++;
	}
	while(Size_StackList(stack) > 0){
		MyNewChar* mcc = (MyNewChar*)Top_StackList(stack);
		printf("%c", *(mcc->pAd));
		Pop_StackList(stack);
		free(mcc);
	}
	Des_StackList(stack);
}

//-----------------------后缀计算输出结果-------------------------------
//831-5*+  ---------->15
/*
对于数字：  进栈
对于符号：
		 从栈中弹出右操作数
		 从栈中弹出左操作数
		 根据符号进行运算
		 将运算结果压入栈中
*/
typedef struct MYNUM{
	StackNode node;
	int val;
}Mynum;

int IsNum(char c){
	return c>='0'&&c<='9';
}

void test04(){

	StackList* stack = Init_StackList();
	char *str = "831-5*+";
	char *p =str;
	int ret =0;

	while(*p!=0){
		//对于数字：  进栈
		if(IsNum(*p)){
			Mynum* num = (Mynum*)malloc(sizeof(Mynum));
			num->val = *p -'0';
			Push_StackList(stack,(StackNode*)num);
		}else{
			//从栈中弹出右操作数
			Mynum* right = (Mynum*)Top_StackList(stack);
			int rN = right->val;
			Pop_StackList(stack);
			free(right);

			//从栈中弹出左操作数
			Mynum* left = (Mynum*)Top_StackList(stack);
			int lN = left->val;
			Pop_StackList(stack);
			free(left);

			switch(*p){
				case '+': ret = lN + rN; break;
				case '-': ret = lN - rN; break;
				case '*': ret = lN * rN; break;
				case '/': ret = lN / rN; break;
				default:
					break;
			}

			Mynum* mc = (Mynum*)malloc(sizeof(Mynum));
			mc->val = ret;
			Push_StackList(stack,(StackNode*)mc);
		}
		p++;
	}

	if(Size_StackList(stack) == 1){
		Mynum* ma = (Mynum*)Top_StackList(stack);
		printf("%d\n",ma->val);
		Pop_StackList(stack);
		free(ma);
	}

	Des_StackList(stack);
}

int main()
{
	test01();
	test02();
	printf("\n");
	test03();
	printf("\n");
	test04();
	printf("\n------------------------------------------------------\n");
	return 0;
}