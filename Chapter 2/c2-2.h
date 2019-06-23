//c2-2.h 线性表的单链表存储结构
//2019/6/19 20:45:15

struct LNode
{
	ElemType data;
	LNode *next;
};

typedef LNode *LinkList;	//另一种定义LinkList的方法