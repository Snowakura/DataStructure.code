//algo3-10.cpp Hanoi�����⣬�����㷨3.5�ĳ���
//2019/6/20 22:19:00

#include "stdio.h"
#include "stdlib.h"		//system()ͷ�ļ�

int c = 0;	//ȫ�ֱ������ᶯ����

void move(char x, int n, char z)
{//��n��Բ�̴�����x�ᵽ����z
	printf("��%i��:��%i���̴�%c�Ƶ�%c\n", ++c, n, x, z);
}

void hanoi(int n, char x, char y, char z)	//�㷨3.5
{//������x�ϰ�ֱ����С���������϶��±��Ϊ1��n��n��Բ��
 //������ᵽ����z�ϡ�y��������������
	if (1 == n)	//(����)
		move(x, 1, z);	//�����Ϊ1��Բ�̴�x�Ƶ�z
	else
	{
		hanoi(n-1, x, z, y);	//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������(���۵ݹ����)
		move(x, n, z);	//�����Ϊn��Բ�̴�x�Ƶ�z
		hanoi(n-1, y, x, z);	//��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��x��������(���۵ݹ����)
	}
}

int main(int argc, char const *argv[])
{
	int n;

	printf("3������Ϊa��b��c,Բ�������a��������b���Ƶ�c����������Բ������");
	scanf("%d", &n);
	hanoi(n, 'a', 'b', 'c');

	system("pause");
	return 0;
}