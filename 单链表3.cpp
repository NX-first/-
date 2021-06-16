#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ListData;
typedef int Status;
typedef struct LNode {
   ListData  data;
   struct LNode  * next;
} ListNode;
typedef ListNode  * LinkList;
LinkList  first;
//��������
void CreateList_L(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(LNode)); // ����ͷ���,��ʹLָ���ͷ���
    cout << "������������Ԫ��:";
    LinkList p,q;
    L->next=NULL;
    p=L;
    for(int i=0,x;i<n;i++){
        LinkList q=new LNode;
        cin>>x;
        q->data=x;
        p->next=q;
        p=p->next;
    }
    p->next=NULL;
}
Status ListDelete(LinkList L,int i,ListData &e)
 {
   int j=0;
   LinkList p=L,q;
   while(p->next&&j<i-1) 
   {
     p=p->next;
     j++;
   }
   if(!p->next||j>i-1) {
     cout << "ɾ��λ��/Ԫ�ش���" << endl;
     return ERROR;
   }
   q=p->next; 
   p->next=q->next;
   e=q->data;
   free(q);
   return OK;
 }
Status ListInsert(LinkList &L,int i,ListData &e)
 { 
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) 
   {
     p=p->next;
     j++;
   }
   if(!p||j>i-1){ 
        cout << "����Ĳ���λ�ã�" << endl;
        return ERROR;
   }
   s=(LinkList)malloc(sizeof(LNode)); // �����½��
   s->data=e; 
   s->next=p->next;
   p->next=s;
   return OK;
 }
void Show_LinkList(LinkList &L)
{
    LinkList p;
    p=L;
    while(p->next){
        p=p->next;
        cout<<p->data<<" ";
        if (p == NULL) break;
    }
    cout<<endl;
}
//��λ����
ListNode * Locate ( LinkList &first, int i ) {
    if ( i < 0){
        cout << "����ĵ�ַ��" << endl;
        return NULL;
    }
    ListNode * p = first;
    int k = 0;
    while ( p != NULL && k < i )
       { p = p->next;  k++; }
    if  ( k == i ) {
        cout << "��λ�õ�Ԫ����:" << p->data << endl;
        return p; 
    }
    else return NULL;
}
//��ֵ����
bool Find ( LinkList &first, ListData value ) {
     ListNode * p = first->next;
     ListNode * q = first->next;
     int seat = 1;
     int num = 1;
     while (q != NULL){
         q=q->next;
         if (p == NULL) break;
         num ++;
     }
     while ( p != NULL && p->data != value ){
         if (p == NULL) break;
         p = p->next;
         seat ++;
     }
     if (seat >= num){
        cout << "���������޴�Ԫ�أ�" << endl;
        return ERROR;
     }
     else {
        cout << "Ԫ��λ����:" << seat << endl;
        return OK;
     }
}

//���Ԫ��
bool FindE( LinkList &first, ListData value ) {
     ListNode * p = first->next;
     ListNode * q = first->next;
     int seat = 1;
     int num = 1;
     while (q != NULL){
         q=q->next;
         if (p == NULL) break;
         num ++;
     }
     while ( p != NULL && p->data != value ){
         if (p == NULL) break;
         p = p->next;
         seat ++;
     }
     if (seat >= num){
        cout << "���������޴�Ԫ�أ�" << endl;
        return ERROR;
     }
     else {
        return OK;
     }
}
//�༶�˵� 
int main()
{
    cout << "1:����������" << endl;
    cout << "2:����������е�Ԫ��" << endl;
    cout << "3:��ֵ����Ԫ��" << endl;
    cout << "4:��λ�ò���Ԫ��" << endl;
    cout << "5:����Ԫ�ص���������" << endl;
    cout << "6:ɾ�������е�ĳ�����" << endl;
    cout << "7.�˳�" << endl;
    cout << endl;
    int command = 0;
    cout << "������Ҫ���еĲ���:";
    cin >> command;
    while(command != 1 && command != 7){
        cout << "��δ������/�Ƿ����룡" <<endl;
        cout << "������Ҫ���еĲ���:";
        cin >> command;
    }
    if (command == 7) return 0;
    cout << "������������:";
    int length;
    cin >> length;
    LinkList L;
    CreateList_L (L, length);
    ListData e,position;
    while(command != 7){
        if (command < 1 || command > 6){
            cout << "�Ƿ����룡" << endl;
        }
        switch(command){
            case 1 :{
                cout << "�ѳɹ�������" << endl;
            }break;

            case 2 :{
                Show_LinkList(L);
            }break;

            case 3 :{
                cout<<"������Ҫ���ҵ�Ԫ��:";
                cin>>e;
                Find (L, e);
                cout << endl;
            }break;

            case 4 :{
                cout << "������Ҫ���ҵ�Ԫ��λ��:";
                cin >> position;
                if (position > length) {
                    cout << "�����Ȳ��㣡" << endl;
                    break;
                }
                Locate (L,position);
                cout << endl;
            }break;

            case 5 :{
                cout << "������Ҫ�����λ��:";
                cin >> position;
                cout << "������Ҫ�����Ԫ��ֵ:";
                cin >> e;
                ListInsert(L,position,e);
                cout << endl;
            }break;

            case 6 :{
                cout << "������Ҫɾ����λ��:";
                cin >> position;
                cout << "������Ҫɾ����Ԫ��ֵ:";
                cin >> e;
                bool judege = FindE(L, e);
                if (judege == ERROR) break;
                ListDelete(L,position,e);
                cout << endl;
            }break;

        }
        cout << endl;
        cout << "������Ҫ���еĲ���:";
        cin >> command;
    }
    return 0;
}
