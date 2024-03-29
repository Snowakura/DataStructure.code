//main2-1.cpp	检验bo2-1.cpp的主程序

#include "../Chapter 1/c1.h"
typedef int ElemType;
#include "c2-1.h"
#include "bo2-1.cpp"
#include "func2-3.cpp"	//包括equal(),comp(),print(),print2()和print1()函数

Status sq(ElemType c1, ElemType c2)
{//数据元素判定函数(平方关系)，LocalElem()调用的函数
	if (c1 == c2 * c2)
		return TRUE;
	else
		return FALSE;
}

void db1(ElemType &c)
{//ListTraverse()调用的另一函数(元素值加倍)
	c *= 2;
}

int main()
{
	SqList L;
	ElemType e, e0;
	Status i;
	int j, k;
	InitList(L);
	printf("初始化L后：L.elem=%u L.length=%d L.listsize=%d\n",
					  L.elem, L.length, L.listsize);

	for (j = 1; j <= 5; j++)
		i = ListInsert(L, 1, j);
	printf("在L的表头依次插入1~5后：*L.elem=");
	for (j = 1; j <= 5; j++)
		cout << *(L.elem + j - 1) << ' ';
	cout << endl;
	printf("L.elem=%u L.length=%d L.listsize=%d\n",
			L.elem, L.length, L.listsize);

	i = ListEmpty(L);
	printf("L是否为空：i=%d(1:是 0:否)\n", i);

	ClearList(L);
	printf("清空L后：L.elem=%u L.length=%d L.listsize=%d\n",
					L.elem, L.length, L.listsize);

	i = ListEmpty(L);
	printf("L是否为空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(L, j, j);
	printf("在L的表尾依次插入1~10后：*L.elem=");
	for(j = 1; j <= 10; j++)
		cout << *(L.elem + j - 1) << ' ';
	cout << endl;
	printf("L.elem=%u L.length=%d L.listsize=%d\n",
			L.elem, L.length, L.listsize);

	ListInsert(L, 1, 0);
	printf("在L的表头插入0后：*L.elem=");
	for (j = 1; j <= ListLength(L); j++)	//ListLength(L)为元素个数
		cout << *(L.elem + j - 1) << ' ';
	cout << endl;
	printf("L.elem=%u(有可能改变) L.length=%d(改变) L.listsize=%d(改变)\n",
			L.elem, L.length, L.listsize);

	GetElem(L, 5, e);
	printf("第5个元素的值为%d\n", e);

	for (j = 10; j <= 11; j++)
	{
		k = LocateElem(L, j, equal);
		if (k)	//k不为0，表明有符合条件的元素，且其位序为k
			printf("第%d个元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}

	for (j = 3; j<= 4; j++)
	{
		k = LocateElem(L, j, sq);
		if (k)	//k不为0，表明有符合条件的元素，且其位序为k
			printf("第%d个元素的值为%d的平方\n", k, j);
		else
			printf("没有值为%d的平方的元素\n", j);
	}

	for (j = 1; j <= 2; j++)
	{
		GetElem(L, j, e0);	//把第j个数据赋给e0
		i = PriorElem(L, e0, e);	//求e0的前驱
		if (i == INFEASIBLE)
			printf("元素%d无前驱\n", e0);
		else
			printf("元素%d的前驱为%d\n", e0, e);
	}

	for (j = ListLength(L) - 1; j <= ListLength(L); j++)	//最后两个数据
	{
		GetElem(L, j, e0);	//把第j个数据赋给e0
		i = NextElem(L, e0, e);	//求e0的后继
		if (i == INFEASIBLE)
			printf("元素%d无后继\n", e0);
		else
			printf("元素%d的后继为%d\n", e0, e);
	}

	k = ListLength(L); //k为表长
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(L, j, e);	//删除第j个数据
		if (i == ERROR)
			printf("删除第%d个元素失败\n", j);
		else
			printf("删除第%d个元素成功，其值为%d\n", j, e);
	}

	printf("依次输出L的元素");
	ListTraverse(L, print1);	//依次对元素调用print1(),输出元素的值

	printf("L的元素值加倍后：");
	ListTraverse(L, db1);	//依次对元素调用db1(),元素值乘2

	ListTraverse(L, print1);
	DestroyList(L);
	printf("销毁L后：L.elem=%u L.length=%d L.listsize=%d\n",
			L.elem, L.length, L.listsize);

	return 0;
}