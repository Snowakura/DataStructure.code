//main3-1.cpp 检验bo3-1.cpp的主程序
//2019/6/19 20:07:05

#include "../Chapter 1/c1.h"
typedef int SElemType;		//定义栈元素类型，此句要加在c3-1.h前面
#include "c3-1.h"
#include "bo3-1.cpp"

void print(SElemType c)
{
	printf("%d ", c);
}

int main(int argc, char const *argv[])
{
	int j;
	SqStack s;
	SElemType e;
	InitStack(s);

	for(j = 1; j<=12; j++)
		Push(s, j);
	printf("栈中元素依次为");
	StackTraverse(s,print);

	Pop(s, e);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否： %d(1:空 0:否)\n", StackEmpty(s));

	GetTop(s, e);
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));

	ClearStack(s);
	printf("清空栈后，栈空否 %d(1:空 0:否)\n", StackEmpty(s));

	DestroyStack(s);
	printf("销毁栈后,s.top=%u s.base=%u s.stacksize=%d\n", s.top, s.base, s.stacksize);

	system("pause");
	return 0;
}