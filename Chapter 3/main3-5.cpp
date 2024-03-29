//main3-5.cpp 检验bo3-5.cpp的主程序
//2019/6/19 22:22:28

#include "../Chapter 1/c1.h"
typedef int SElemType;	//定义栈元素的类型
#include "bo3-5.cpp"

void print(SElemType c)
{
	printf("%d ", c);
}

int main(int argc, char const *argv[])
{
	int j;
	LinkStack s;
	SElemType e;
	InitStack(s);	//初始化栈s
	for(j = 1; j <= 5; j++)	//将2,4,6,8,10入栈
		Push(s, 2 * j);
	printf("栈中的元素从栈底到栈顶依次为");
	StackTraverse(s, print);
	Pop(s, e);
	printf("弹出的栈顶元素为%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	GetTop(s, e);
	printf("当前栈顶元素为%d,栈的长度为%d\n", e, StackLength(s));
	ClearStack(s);
	printf("清空栈后，栈空否：%d(1:空 0:否),栈的长度为%d\n", StackEmpty(s), StackLength(s));
	DestroyStack(s);

	system("pause");
	return 0;
}