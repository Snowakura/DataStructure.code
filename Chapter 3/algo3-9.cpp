//algo3-9.cpp �õݹ麯������Թ�����(������н�)
//2019/6/20 21:48:07

#include "../Chapter 1/c1.h"	//���ݡ�PASCAL������ơ�(֣��������)�еĳ���ı�
#include "func3-1.cpp"			//����ǽԪ��ֵΪ0����ͨ��·��Ϊ-1��ͨ��·��Ϊ�㼣

void Try(PosType cur, int curstep)
{//�ɵ�ǰλ��cur����ǰ����curstep��̽��һ��
	int i;
	PosType mnext;	//��һ��λ��

	PosType direc[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};	//{��������������}���ƶ���������Ϊ��������

	for (i = 0; i <= 3; i++)
	{
		mnext.x = cur.x + direc[i].x;	//�����ƶ����򣬸���һ��λ�ø�ֵ
		mnext.y = cur.y + direc[i].y;

		if(m[mnext.x][mnext.y] == -1)	//��һ��λ����ͨ·
		{
			m[mnext.x][mnext.y] = ++curstep;	//����һ��λ����Ϊ�㼣
			if (mnext.x != mend.x || mnext.y != mend.y)	//û���յ�
				Try(mnext, curstep);	//����һ��λ�ü�����̽(���۵ݹ���ã����յ����)
			else	//���յ�
			{
				Print();	//������(���ڣ� ���ٵݹ����)
				printf("\n");
			}

			m[mnext.x][mnext.y] = -1;	//�ָ�Ϊͨ·���Ա�����һ��������̽��һ��·
			curstep--;	//�㼣��1
		}
	}
}

int main(int argc, char const *argv[])
{
	Init(-1);	//��ʼ���Թ���ͨ��ֵΪ-1

	printf("���Թ�����ڵ����ڵ�һ��·�����£�\n");
	m[mbegin.x][mbegin.y] = 1;	//��ڵ��㼣Ϊ1
	Try(mbegin, 1);	//�ɵ�1�������̽��

	system("pause");
	return 0;
}