//bo3-1.cpp	˳��ջ(�洢�ṹ��c3-1.h����)�Ļ�������(9��)
//2019/6/19 13:33:42

void InitStack(SqStack &S)
{//����һ����ջS
	if(!(S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType))))
		exit(OVERFLOW);	//�洢����ʧ��
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{//����ջS��S���ٴ���
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
}

void ClearStack(SqStack &S)
{//��S��Ϊ��ջ
	S.top = S.base;
}

Status StackEmpty(SqStack S)
{//��ջSΪ��ջ������TRUE�����򷵻�FALSE
	if(S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)
{//����S��Ԫ�ظ�������ջ�ĳ���
	return S.top - S.base;
}

Status GetTop(SqStack S, SElemType &e)
{//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top > S.base)
	{
		e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}

void Push(SqStack &S, SElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize)	//ջ����׷�Ӵ洢�ռ�
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof (SElemType));

		if (!S.base)
			exit(OVERFLOW);		//�洢����ʧ��

		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}

	*(S.top)++ = e;
}

Status Pop(SqStack &S, SElemType &e)
{//��ջ���գ�ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.top == S.base)
		return ERROR;
	e= *--S.top;
	return OK;
}

void StackTraverse(SqStack S, void(*visit)(SElemType))
{//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()
	while(S.top > S.base)
		visit(*S.base++);
	printf("\n");
}