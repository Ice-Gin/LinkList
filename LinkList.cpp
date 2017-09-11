#include "iostream"
using namespace std;
typedef struct Node//结点类型定义
{
	char data;
	struct Node * next;
}Node,*LinkList;//*LinkList用来定义单链表的头结点,Node用来定义单链表中的结点（头结点不属于单链表的内容）

LinkList Init_List()//初始化单链表
{
	
	Node *L;
	L = (LinkList)malloc(sizeof(Node));//强制类型转换
	if (L == NULL)
	{
		printf("初始化失败!\n");
		exit(-1);
	}
	L->next = NULL;
	return L;
}
void CreatFromHead_LinkList(LinkList L)//头插法建表（逆序）
{
	Node *s;
	char c;
	int flag = 1;
	cout << "请输入内容，并以“$”结束" << endl;
	while (flag)
	{
		cin >> c;
		if (c != '$')
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next;
			L->next = s;
		}
		else
		{
			flag = 0;
		}
	}
}
void CreatFromTail_LinkList(LinkList L)//尾插法建表
{
	Node *r, *s;//r的作用是以一个独立的结点来等价新节点，以此来持续链接新的结点，简单来说，r始终用来等于链表中的最后一个结点，再从它后面加新结点
	char c;
	int flag = 1;
	r = L;
	cout << "请输入内容，并以“$”结束"<<endl;
	while (flag)
	{
		cin >> c;
		if (c != '$')
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			r->next = s;
			r = s;
		}
		else
		{
			flag = 0;
			r->next = NULL;
		}
	}
}
int Length_LinkList(LinkList L)//计算单链表长度
{
	Node *p;
	p = L->next;
	int Length = 0;
	while (p!=NULL)
	{
		p = p->next;
		Length++;
	}
	return Length;
}
void Input_Length_LinkList(LinkList L)//输出单链表长度
{
	cout<<"单链表的长度为：" << Length_LinkList(L)<<endl;
}
void Dispaly_LinkList(LinkList L)//输出单链表内容
{
	cout << "单链表的内容是："<<endl;
	Node *p;
	p = L->next;
	while (p != NULL)
	{
		cout << p->data<<" ";
		p = p->next;
	}
	cout << endl;
}
void Get_LinkList(LinkList L)//查找指定序号对应的元素
{
	Node *p;
	p = L;
	int i;
	flag://flag2
	cout << "请选择序号：" << endl;
	cin >> i;
	if (i<1 || i>Length_LinkList(L))
	{
		cout << "超出范围，请重新选择"<<endl;
		goto flag;//flag2
	}
	else
	{
		for (int j = 0; j < i; j++)
			p = p->next;
	}
	cout<< "第"<<i<<"元素是："<<p->data << endl;
}
void Insert_LinkList(LinkList L)//给指定位置插入元素
{
	Node *p,*q;
	p = L;
	q = Init_List();//初始化q结点
	char e;
	int i;
	flag://flag3
	cout << "请选择插入的位置"<< endl;
	cin >> i;
	if (i<1 || i>Length_LinkList(L)+1)//判断插入的位置是否合理
	{
		cout << "超出范围，请重新选择" << endl;
		goto flag;//flag3
	}
	else if (i == Length_LinkList(L)+1)//插在表尾
	{
		cout << "请输入插入的元素："<<endl;
		cin >> e;
		for (int j = 0; j < i-1; j++)
			p = p->next;
		q->data = e;
		p->next = q;
	}
	else//插在表中
	{
		cout << "请输入插入的元素：" << endl;
		cin >> e;
		for (int j = 0; j < i-1; j++)
			p = p->next;
		q->data = e;
		q->next = p->next;
		p->next = q;
	}
}
void Delete_LinkList(LinkList L)//删除序号位置的元素
{
	Node *p,*q;
	p = L;
	int i;
	flag://flag4
	cout << "请选择要删除的元素序号"<<endl;
	cin >> i;
	if (i<1||i>Length_LinkList(L))
	{
		cout << "超出单链表范围，请重新输入"<<endl;
		goto flag;//flag4
	}
	else
	{
		for (int j = 0; j < i-1; j++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		int e = q->data;
		free(q);
	}
}
int main()
{
	LinkList  L;
	L=Init_List();
	flag://flag1
	cout << "*------------------------------------------------------*" << endl;//从这开始选择功能
	cout << "请选择功能："
		<< endl << "1.正序建表"
		<< endl << "2.逆序建表"
		<< endl << "3.输出单链表的长度"
		<< endl << "4.输出单链表的内容"
		<< endl << "5.查找指定序号的元素"
		<< endl << "6.在指定位置插入元素"
		<< endl << "7.删除指定序号的元素"
		<< endl << "0.退出程序" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:CreatFromTail_LinkList(L); break;
	case 2:CreatFromHead_LinkList(L); break;
	case 3:Input_Length_LinkList(L); break;
	case 4:Dispaly_LinkList(L); break;
	case 5:Get_LinkList(L); break;
	case 6:Insert_LinkList(L); break;
	case 7:Delete_LinkList(L); break;
	default:cout << "谢谢使用！"<<endl; 
		    system("pause");
		return 0;
	}
	cout << "是否继续使用顺序表其他功能？"<<endl<<"1 for 是；2 for 否" << endl;
	int ss;
	cin >> ss;
	if (ss == 1)
	{
		goto flag;//flag1
	}
	system("pause");
	return 0;

}
