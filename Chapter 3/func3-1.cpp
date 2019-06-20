//迷宫求解
//func3-1.cpp algo3-5.cpp、algo3-9.cpp、algo3-11.cpp要调用的函数、结构和全局变量
//2019/6/20 15:50:02
//入口坐标和出口坐标用begin和end会提示it's ambiguous，故改为mbegin和mend

struct PosType		//迷宫坐标位置类型： PosType
{					//					_________
	int x;	//行值	//					| x	| y	|
	int y;	//列值	//					|___|___|
};
#define MAXLENGTH 25	//设置迷宫的最大行列为25
typedef int MazeType[MAXLENGTH][MAXLENGTH];	//迷宫数组类型[行][列]
//全局变量

MazeType m;	//迷宫数组
int x, y;	//迷宫的行数，列数
PosType mbegin, mend;	//迷宫的入口坐标，出口坐标

void Print()
{//输出迷宫的解(m数组)
	int i, j;

	for(i = 0; i < x; i++)
	{
		for(j = 0; j <y; j++)
			printf("%3d", m[i][j]);
		printf("\n");
	}
}

void Init(int k)
{//设定迷宫布局(墙为值0，通道值为k)
	int i, j, x1, y1;

	printf("请输入迷宫的行数，列数(包括外墙)：");
	scanf("%d,%d", &x, &y);

	for(i = 0; i < x; i++)	//定义周边值为0(外墙)
	{
		m[0][i] = 0;	//行周边
		m[x - 1][i] = 0;
	}
	for(i = 0; i < y - 1; i++)	//定义周边值为0(外墙)
	{
		m[i][0] = 0;	//列周边
		m[i][y - 1] = 0;
	}

	for(i = 1; i < x - 1; i++)
		for(j = 1; j < y - 1; j++)
			m[i][j] = k;	//定义除外墙，其余都是通道，初值为k

	printf("请输入迷宫内墙单元数：");
	scanf("%d", &j);
	printf("请依次输入迷宫内墙每个单元的行数，列数：\n");
	for(i = 1; i <= j; i++)
	{
		scanf("%d,%d", &x1, &y1);
		m[x1][y1] = 0;	//修改墙的值为0
	}

	printf("迷宫的结构如下：\n");
	Print();

	printf("请输入入口的行数，列数：");
	scanf("%d,%d", &mbegin.x, &mbegin.y);

	printf("请输入出口的行数，列数：");
	scanf("%d,%d", &mend.x, &mend.y);

}