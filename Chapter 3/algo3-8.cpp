//algo3-8.cpp 用递归调用求Ackerman(m, n)的值
//m,n不可取值过大
//
//			|- n + 1						若m = 0
//Ack(m,n)=-|- Ack(m - 1,1)					若m = 0
//			|- Acl(m - 1, Ack(m, n - 1))	其他情形
//			
//2019/6/20 21:36:09

#include "stdio.h"
#include "stdlib.h"		//system()头文件

int ack(int m, int n)
{
	int z;

	if (0 == m)
		z = n + 1;	//出口
	else if ( 0 == n)
		z = ack(m - 1, 1);	//对形参m降价
	else
		z = ack(m - 1, ack(m, n - 1));	//对m、n降价

	return z;
}

int main(int argc, char const *argv[])
{
	int m, n;

	printf("Please input m,n:");
	scanf("%d,%d", &m, &n);
	printf("Ack(%d,%d)=%d\n", m, n, ack(m, n));
	
	system("pause");
	return 0;
}