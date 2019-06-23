//algo2-1.cpp ʵ���㷨2.1�ĳ���
//�����ǲ������Ա�Ķ�̬����˳��洢�ṹ(c2-1.h)���ü������ǻ����������㷨�ĳ���
//���Ƕ�������bo2-1.cpp�������������ļ���

#include "../Chapter 1/c1.h"
typedef int ElemType;
#include "c2-1.h"		//�������Ա�Ķ�̬����˳��洢�ṹ
#include "bo2-1.cpp"	//����ʹ��bo2-1.cpp�ֵĻ�������
#include "func2-3.cpp"	//����equal()��comp()��print()��print2()��print1()����

void Union(SqList &La,SqList Lb)	//�㷨2.1
{//�����������Ա�Lb�е�����La�ֵ�����Ԫ�ز��뵽La��
	ElemType e;
	int La_len,Lb_len;
	int i;

	La_len = ListLength(La);	//�����Ա���
	Lb_len = ListLength(Lb);
	
	for (i = 1; i <= Lb_len; i++)
		{
			GetElem(Lb, i, e);	//ȡLb�е�i������Ԫ�ظ���e
			if(!LocateElem(La, e, equal))	//La�в����ں�e��ͬ��Ԫ�أ������֮
				ListInsert(La, ++La_len, e);
		}	
}


int main()
{
	SqList La, Lb;
	int j;
	InitList(La);	//�����ձ�La���粻�ɹ�������˳����������

	for (j = 1; j <= 5; j++)	//�ڱ�La�в������Ԫ�أ�����Ϊ1,2,3,4,5
		ListInsert(La, j, j);

	printf("La= ");	//�����La������
	ListTraverse(La, print1);

	InitList(Lb);	//�����ձ�Lb
	for (j = 1; j <= 5; j++)	//�ڱ�Lb�в������Ԫ�أ�����Ϊ2,4,6,8,10
		ListInsert(Lb, j, 2 * j);

	printf("Lb= ");	//�����Lb������
	ListTraverse(Lb, print1);

	Union(La, Lb);	//����Union(),��Lb������������Ԫ�ز���La

	printf("new La=");	//����±�La������
	ListTraverse(La, print1);
	
	return 0;
}