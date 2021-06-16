#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0;
typedef int status;
typedef char TElemType;
//二叉树的结构体定义
typedef struct BiTNode
{

	TElemType data;

	struct BiTNode  *lchild,*rchild; 

} BiTNode,*BiTree;
//创建二叉树，套娃 
void CreatBiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch == '#')T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
}
//先序遍历二叉树
void DLR(BiTree T)
{
	if(T)
	{
		cout<<T->data;
		DLR(T->lchild);
		DLR(T->rchild);
	}
} 
//中序遍历二叉树
void LDR(BiTree T)
{
	if(T)
	{

		LDR(T->lchild);
		cout<<T->data;
		LDR(T->rchild);
	}
} 
//后序遍历二叉树
void LRD(BiTree T)
{
	if(T)
	{
		LRD(T->lchild);
		LRD(T->rchild);
		cout<<T->data; 
	}
} 
//销毁二叉树
void Destroy(BiTree &T)
{
	if(T)
	{
		LRD(T->lchild);
		LRD(T->rchild);
		free(T);
	}
} 
int main()
{
	int i;
	BiTree T = NULL;
	printf("命令菜单：\n	1.建立二叉树	2.先序遍历	3.中序遍历\n	4.后序遍历	5.销毁二叉树	6.退出\n");
	printf("请输入命令:\n");
	scanf("%d",&i);
	while(i != 6)
	{
		switch(i)
		{
			case 1:	printf("\n请输入要建立的二叉树中的元素，#代表空树\n");
					CreatBiTree(T);
					printf("二叉树建立成功\n");
					printf("\n请继续输入命令：");
					break;
			case 2:	printf("先序遍历的结果为：");
					DLR(T);
					printf("\n\n请继续输入命令：");
					break;
			case 3:	printf("中序遍历的结果为：");
					LDR(T);
					printf("\n\n请继续输入命令：");
					break;
			case 4:	printf("后序遍历的结果为：");
					LRD(T);
					printf("\n\n请继续输入命令：");
					break;
			case 5:	Destroy(T);
					printf("二叉树已销毁\n");
					printf("\n\n请继续输入命令：");
					break;
			default: printf("\n输入命令出错，请重新输入命令：");
		}
	scanf("%d",&i);
	fflush(stdin);
	}
 }
