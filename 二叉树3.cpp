#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0;
typedef int status;
typedef char TElemType;
//�������Ľṹ�嶨��
typedef struct BiTNode
{

	TElemType data;

	struct BiTNode  *lchild,*rchild; 

} BiTNode,*BiTree;
//���������������� 
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
//�������������
void DLR(BiTree T)
{
	if(T)
	{
		cout<<T->data;
		DLR(T->lchild);
		DLR(T->rchild);
	}
} 
//�������������
void LDR(BiTree T)
{
	if(T)
	{

		LDR(T->lchild);
		cout<<T->data;
		LDR(T->rchild);
	}
} 
//�������������
void LRD(BiTree T)
{
	if(T)
	{
		LRD(T->lchild);
		LRD(T->rchild);
		cout<<T->data; 
	}
} 
//���ٶ�����
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
	printf("����˵���\n	1.����������	2.�������	3.�������\n	4.�������	5.���ٶ�����	6.�˳�\n");
	printf("����������:\n");
	scanf("%d",&i);
	while(i != 6)
	{
		switch(i)
		{
			case 1:	printf("\n������Ҫ�����Ķ������е�Ԫ�أ�#�������\n");
					CreatBiTree(T);
					printf("�����������ɹ�\n");
					printf("\n������������");
					break;
			case 2:	printf("��������Ľ��Ϊ��");
					DLR(T);
					printf("\n\n������������");
					break;
			case 3:	printf("��������Ľ��Ϊ��");
					LDR(T);
					printf("\n\n������������");
					break;
			case 4:	printf("��������Ľ��Ϊ��");
					LRD(T);
					printf("\n\n������������");
					break;
			case 5:	Destroy(T);
					printf("������������\n");
					printf("\n\n������������");
					break;
			default: printf("\n������������������������");
		}
	scanf("%d",&i);
	fflush(stdin);
	}
 }
