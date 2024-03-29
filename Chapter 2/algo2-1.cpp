//algo2-1.cpp 实现算法2.1的程序
//以下是采用线性表的动态分配顺序存储结构(c2-1.h)调用几个不是基本操作的算法的程序，
//他们都包含了bo2-1.cpp基本操作函数文件。

#include "../Chapter 1/c1.h"
typedef int ElemType;
#include "c2-1.h"		//采用线性表的动态分配顺序存储结构
#include "bo2-1.cpp"	//可以使用bo2-1.cpp种的基本操作
#include "func2-3.cpp"	//包括equal()、comp()、print()、print2()、print1()函数

void Union(SqList &La,SqList Lb)	//算法2.1
{//将所有在线性表Lb中但不在La种的数据元素插入到La中
	ElemType e;
	int La_len,Lb_len;
	int i;

	La_len = ListLength(La);	//求线性表长度
	Lb_len = ListLength(Lb);
	
	for (i = 1; i <= Lb_len; i++)
		{
			GetElem(Lb, i, e);	//取Lb中第i个数据元素赋给e
			if(!LocateElem(La, e, equal))	//La中不存在和e相同的元素，则插入之
				ListInsert(La, ++La_len, e);
		}	
}


int main()
{
	SqList La, Lb;
	int j;
	InitList(La);	//创建空表La。如不成功，则会退出程序的运行

	for (j = 1; j <= 5; j++)	//在表La中插入五个元素，依次为1,2,3,4,5
		ListInsert(La, j, j);

	printf("La= ");	//输出表La的内容
	ListTraverse(La, print1);

	InitList(Lb);	//创建空表Lb
	for (j = 1; j <= 5; j++)	//在表Lb中插入五个元素，依次为2,4,6,8,10
		ListInsert(Lb, j, 2 * j);

	printf("Lb= ");	//输出表Lb的内容
	ListTraverse(Lb, print1);

	Union(La, Lb);	//调用Union(),将Lb中满足条件的元素插入La

	printf("new La=");	//输出新表La的内容
	ListTraverse(La, print1);
	
	return 0;
}