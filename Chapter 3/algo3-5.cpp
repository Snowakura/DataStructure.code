//algo3-5.cpp ����ջ����Թ�����(ֻ���һ���⣬�㷨3.3)
//2019/6/20 16:14:21

#include "../Chapter 1/c1.h"
#include "func3-1.cpp"

int curstep = 1;	//��ǰ�㼣����ֵ(����ڴ�)Ϊ1		SElemType
struct SElemType	//ջ��Ԫ������(����ͼ)			______________________
{					//								|ord|seat.x|seat.y|di|	
	int ord;		//ͨ������·���ϵ�"���"		|___|______|______|__|
	PosType seat;	//ͨ�������Թ��ֵ�"����λ��"
	int di;			//�Ӵ�ͨ����������һͨ�����"����"(0~3��ʾ��~��)
};

#include "c3-1.h"	//����˳��ջ�洢�ṹ
#include "bo3-1.cpp"	//����˳��ջ�Ļ�����������

//����ǽԪ��ֵΪ0����ͨ��·��Ϊ1������ͨ��·��Ϊ-1��ͨ��·��Ϊ�㼣
Status Pass(PosType b)
{//���Թ�m��b������Ϊ1(��ͨ��·��)������OK�����򷵻�ERROR
	if (m[b.x][b.y] == 1)
		return OK;
	else
		return ERROR;
}

void FootPrint(PosType a)
{//ʹ�Թ�m��a���ֵ��Ϊ�㼣(curstep)
	m[a.x][a.y] = curstep;
}

void NextPos(PosType &c, int di)
{//���ݵ�ǰλ�ü��ƶ����������һλ��
	PosType direc[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};	//{��������������}���ƶ���������Ϊ��������
	c.x += direc[di].x;
	c.y += direc[di].y;
}

void MarkPrint(PosType b)
{//ʹ�Թ�m��b�����ű�Ϊ-1(����ͨ����·��)
	m[b.x][b.y] = -1;
}

Status MazePath(PosType start, PosType end)	//�㷨3.3
{//���Թ�m�д��ڴ����start������end��ͨ���������һ��
 //�����ջ��(��ջ�׵�ջ��)��������TRUE�����򷵻�FALSE
	SqStack S;	//˳��ջ
	PosType curpos;	//��ǰλ��
	SElemType e;	//ջԪ��
	InitStack(S);	//��ʼ��ջ
	
	curpos = start;	//��ǰλ�������

	do
	{
		if (Pass(curpos))
		{//��ǰλ�ÿ���ͨ��������δ���ߵ�����ͨ����
			FootPrint(curpos);	//�����㼣
			e.ord  = curstep;
			e.seat = curpos;
			e.di   = 0;
			Push(S, e);	//��ջ��ǰλ�ü�״̬
			curstep++;	//�㼣��1
			if (curpos.x == end.x && curpos.y == end.y)	//�����յ�(����)
				return TRUE;
			NextPos(curpos, e.di);	//�ɵ�ǰλ�ü��ƶ�����ȷ����һ����ǰλ��
		}
		else
		{//��ǰλ�ò���ͨ��
			if(!StackEmpty(S))	//ջ����
			{
				Pop(S, e);	//��ջ��ǰһλ��
				curstep--;	//�㼣��1
				while(e.di == 3 && !StackEmpty(S))	//ǰһλ�ô������һ������(��)
				{
					MarkPrint(e.seat);	//��ǰһλ�����²���ͨ���ı��(-1)
					Pop(S, e);	//���˻�һ��
					curstep--;	//�㼣�ټ�1
				}
				if (e.di < 3)	//û�����һ������(��)
				{
					e.di++;	//����һ������̽��
					Push(S, e);	//��ջ��λ�õ���һ������
					curstep++;	//�㼣��1
					curpos = e.seat;	//ȷ����ǰλ��
					NextPos(curpos, e.di);	//ȷ����һ����ǰλ���Ǹ��·����ϵ����ڿ�
				}
			} 
		}
	}while(!StackEmpty(S));

	return FALSE;
}

int main(int argc, char const *argv[])
{
	Init(1);	//��ʼ���Թ���ͨ��ֵΪ1

	if (MazePath(mbegin, mend))	//��ͨ·
	{
		printf("���Թ�����ڵ����ڵ�һ��·�����£�\n");
		Print();	//�����ͨ·
	}
	else
		printf("���Թ�û�д���ڵ����ڵ�·��\n");

	system("pause");
	return 0;
}