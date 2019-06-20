//algo3-10.cpp Hanoi塔问题，调用算法3.5的程序
//2019/6/20 22:19:00

#include "stdio.h"
#include "stdlib.h"		//system()头文件

int c = 0;	//全局变量，搬动次数

void move(char x, int n, char z)
{//第n个圆盘从塔座x搬到塔座z
	printf("第%i步:将%i号盘从%c移到%c\n", ++c, n, x, z);
}

void hanoi(int n, char x, char y, char z)	//算法3.5
{//将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘
 //按规则搬到塔座z上。y可用作辅助塔座
	if (1 == n)	//(出口)
		move(x, 1, z);	//将编号为1的圆盘从x移到z
	else
	{
		hanoi(n-1, x, z, y);	//将x上编号为1至n-1的圆盘移到y，z做辅助塔(降价递归调用)
		move(x, n, z);	//将编号为n的圆盘从x移到z
		hanoi(n-1, y, x, z);	//将y上编号为1至n-1的圆盘移到z，x做辅助塔(降价递归调用)
	}
}

int main(int argc, char const *argv[])
{
	int n;

	printf("3个塔座为a、b、c,圆盘最初在a座，借助b座移到c座。请输入圆盘数：");
	scanf("%d", &n);
	hanoi(n, 'a', 'b', 'c');

	system("pause");
	return 0;
}