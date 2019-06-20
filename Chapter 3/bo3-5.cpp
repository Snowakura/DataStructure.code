//bo3-5.cpp ��ջ(�洢�ṹ��c2-2.h����)�Ļ�������(4��)
//���ֲ�������bo2-8.cpp�еĺ�����������
//��һ���ֻ����������ɵ���bo2-8.cpp�еĺ���(ȡ����)����
//2019/6/19 22:22:02

typedef SElemType ElemType;	//ջ������ͺ�����������һ��
#include "../Chapter 2/c2-2.h"	//������洢�ṹ
typedef LinkList LinkStack;	//LinkList��ָ��ջ����ָ������
#define InitStack InitList	//InitStack()��InitList()������ͬ����ͬ
#define DestroyStack DestroyList
#define ClearStack ClearList
#define StackEmpty ListEmpty
#define StackLength ListLength
#include "../Chapter 2/bo2-8.cpp"	//��ͷ��㵥����Ļ�������

Status GetTop(LinkStack S, SElemType &e)
{//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	return GetElem(S, 1, e);
}

Status Push(LinkStack &S, SElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	return ListInsert(S, 1, e);
}

Status Pop(LinkStack &S, SElemType &e)
{//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	return ListDelete(S, 1, e);
}

void StackTraverse(LinkStack S, void(*visit)(SElemType))
{//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()
	LinkStack temp, p = S;	//pָ��ջ��Ԫ��
	InitStack(temp);	//��ʼ����ʱջtemp
	while(p)
	{
		Push(temp, p->data);	//��Sջ����ջ�ף����ν�ջԪ����ջ��tempջ
		p = p->next;
	}
	ListTraverse(temp, visit);	//����temp���Ա�
}