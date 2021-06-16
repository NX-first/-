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
//建立链表
void CreateList_L(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(LNode)); // 产生头结点,并使L指向此头结点
    cout << "依次输入链表元素:";
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
     cout << "删除位置/元素错误！" << endl;
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
        cout << "错误的插入位置！" << endl;
        return ERROR;
   }
   s=(LinkList)malloc(sizeof(LNode)); // 生成新结点
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
//按位查找
ListNode * Locate ( LinkList &first, int i ) {
    if ( i < 0){
        cout << "错误的地址！" << endl;
        return NULL;
    }
    ListNode * p = first;
    int k = 0;
    while ( p != NULL && k < i )
       { p = p->next;  k++; }
    if  ( k == i ) {
        cout << "该位置的元素是:" << p->data << endl;
        return p; 
    }
    else return NULL;
}
//按值查找
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
        cout << "单链表中无此元素！" << endl;
        return ERROR;
     }
     else {
        cout << "元素位置是:" << seat << endl;
        return OK;
     }
}

//检测元素
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
        cout << "单链表中无此元素！" << endl;
        return ERROR;
     }
     else {
        return OK;
     }
}
//多级菜单 
int main()
{
    cout << "1:创建单链表" << endl;
    cout << "2:输出单链表中的元素" << endl;
    cout << "3:按值查找元素" << endl;
    cout << "4:按位置查找元素" << endl;
    cout << "5:插入元素到单链表里" << endl;
    cout << "6:删除链表中的某个结点" << endl;
    cout << "7.退出" << endl;
    cout << endl;
    int command = 0;
    cout << "请输入要进行的操作:";
    cin >> command;
    while(command != 1 && command != 7){
        cout << "还未创建表！/非法输入！" <<endl;
        cout << "请输入要进行的操作:";
        cin >> command;
    }
    if (command == 7) return 0;
    cout << "请输入链表长度:";
    int length;
    cin >> length;
    LinkList L;
    CreateList_L (L, length);
    ListData e,position;
    while(command != 7){
        if (command < 1 || command > 6){
            cout << "非法输入！" << endl;
        }
        switch(command){
            case 1 :{
                cout << "已成功创建表！" << endl;
            }break;

            case 2 :{
                Show_LinkList(L);
            }break;

            case 3 :{
                cout<<"请输入要查找的元素:";
                cin>>e;
                Find (L, e);
                cout << endl;
            }break;

            case 4 :{
                cout << "请输入要查找的元素位置:";
                cin >> position;
                if (position > length) {
                    cout << "链表长度不足！" << endl;
                    break;
                }
                Locate (L,position);
                cout << endl;
            }break;

            case 5 :{
                cout << "请输入要插入的位置:";
                cin >> position;
                cout << "请输入要插入的元素值:";
                cin >> e;
                ListInsert(L,position,e);
                cout << endl;
            }break;

            case 6 :{
                cout << "请输入要删除的位置:";
                cin >> position;
                cout << "请输入要删除的元素值:";
                cin >> e;
                bool judege = FindE(L, e);
                if (judege == ERROR) break;
                ListDelete(L,position,e);
                cout << endl;
            }break;

        }
        cout << endl;
        cout << "请输入要进行的操作:";
        cin >> command;
    }
    return 0;
}
