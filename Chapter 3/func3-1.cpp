//�Թ����
//func3-1.cpp algo3-5.cpp��algo3-9.cpp��algo3-11.cppҪ���õĺ������ṹ��ȫ�ֱ���
//2019/6/20 15:50:02
//�������ͳ���������begin��end����ʾit's ambiguous���ʸ�Ϊmbegin��mend

struct PosType		//�Թ�����λ�����ͣ� PosType
{					//					_________
	int x;	//��ֵ	//					| x	| y	|
	int y;	//��ֵ	//					|___|___|
};
#define MAXLENGTH 25	//�����Թ����������Ϊ25
typedef int MazeType[MAXLENGTH][MAXLENGTH];	//�Թ���������[��][��]
//ȫ�ֱ���

MazeType m;	//�Թ�����
int x, y;	//�Թ�������������
PosType mbegin, mend;	//�Թ���������꣬��������

void Print()
{//����Թ��Ľ�(m����)
	int i, j;

	for(i = 0; i < x; i++)
	{
		for(j = 0; j <y; j++)
			printf("%3d", m[i][j]);
		printf("\n");
	}
}

void Init(int k)
{//�趨�Թ�����(ǽΪֵ0��ͨ��ֵΪk)
	int i, j, x1, y1;

	printf("�������Թ�������������(������ǽ)��");
	scanf("%d,%d", &x, &y);

	for(i = 0; i < x; i++)	//�����ܱ�ֵΪ0(��ǽ)
	{
		m[0][i] = 0;	//���ܱ�
		m[x - 1][i] = 0;
	}
	for(i = 0; i < y - 1; i++)	//�����ܱ�ֵΪ0(��ǽ)
	{
		m[i][0] = 0;	//���ܱ�
		m[i][y - 1] = 0;
	}

	for(i = 1; i < x - 1; i++)
		for(j = 1; j < y - 1; j++)
			m[i][j] = k;	//�������ǽ�����඼��ͨ������ֵΪk

	printf("�������Թ���ǽ��Ԫ����");
	scanf("%d", &j);
	printf("�����������Թ���ǽÿ����Ԫ��������������\n");
	for(i = 1; i <= j; i++)
	{
		scanf("%d,%d", &x1, &y1);
		m[x1][y1] = 0;	//�޸�ǽ��ֵΪ0
	}

	printf("�Թ��Ľṹ���£�\n");
	Print();

	printf("��������ڵ�������������");
	scanf("%d,%d", &mbegin.x, &mbegin.y);

	printf("��������ڵ�������������");
	scanf("%d,%d", &mend.x, &mend.y);

}