#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define stack_init_size 100 
#define stackincreament 10  
typedef int SElemType;
typedef int Status;
typedef struct {	
	SElemType *base;		
	SElemType *top;		
	int SSize;			
}SqStack;
void initstack(SqStack &S) {
	S.base = (SElemType *)malloc(stack_init_size * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);

	S.top = S.base;
	S.SSize = stack_init_size;
}//��ʼ��ջ
void creatstack(SqStack &S){
    int stacklength;
    cout << "������ջ�ĳ���:";
    cin >> stacklength;
    if (S.top - S.base >= stacklength) {
        cout << "�Ƿ����ȣ�" << endl;
    }
    int StackElem[stack_init_size];
    for (int i = 0; i < stack_init_size; i++){
        StackElem[i] = -1;
    }
    cout << "���봴����ջԪ��:";
    for (int j = 0; j < stacklength; j++){
        cin >> StackElem[j];
    }
    int k = 0;
    while (StackElem[k] != -1)
    {
        *S.top++ = StackElem[k];
        k++;
    }
}
Status gettop(SqStack S, SElemType &e) {
	if (S.top == S.base)
		return 0;
	e = *(S.top - 1);
	return 1;
}
Status push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.SSize) {
		S.base = (SElemType *)realloc(S.base, (S.SSize + stackincreament) * sizeof(SElemType));
		if (!S.base){
			cout << "��ջ����ʧ�ܣ�" << endl;
			return ERROR;
		}
		S.top = S.base + S.SSize;
		S.SSize += stackincreament;
	}
	*S.top++ = e;
	cout << "��ջ�����ɹ���" << endl;
	return OK;
}
Status pop(SqStack &S, SElemType &e) {
	if (S.base == S.top){
		cout << "��ջ����ʧ�ܣ�" << endl;
		return ERROR;
	}
	e = *--S.top;
	cout << "��ջ�����ɹ���" << endl;
	return OK;
}
Status StackPrint(SqStack &S) {
    int *p = S.base;
    int e;
    while (p != S.top){
        e = *p;
        cout << e << " ";
        *p ++;
    }
    cout << endl;
    return OK;
}
Status StackLength(SqStack &S)
{ 
    return S.top-S.base;
}
int main()
{
    cout << "1:����һ��ջ" << endl;
    cout << "2:��ջ����" << endl;
    cout << "3:��ջ����" << endl;
    cout << "4:���ջԪ��" << endl;
    cout << "5:�˳�" << endl;

    int command = 0;
    cout << "������Ҫ���еĲ���:";
    cin >> command;

    while(command != 1 && command != 5){ //Ҫô����ջ��Ҫô�˳���������Ϊ�Ƿ�����
        cout << "��δ����ջ��/�Ƿ����룡" <<endl;
        cout << "������Ҫ���еĲ���:";
        cin >> command;
    }
    if (command == 5) {
        cout << "�˳�����!" << endl;
        return 0;
    }
	SqStack S;
	initstack(S);
    creatstack(S);
    SElemType e;
    while(command != 5){
        if (command < 1 || command > 6){
            cout << "�Ƿ����룡" << endl;
        }
        switch(command){
            case 1 :{
                cout << "�Ѵ����ɹ���" << endl;
            }break;

            case 2 :{
                cout << "������ջԪ��:";
                cin >> e;
                push(S, e);
            }break;

            case 3 :{
                pop(S, e);
            }break;

            case 4 :{
                StackPrint(S);
            }break;

            case 5 :{
                cout << "�˳�����!" << endl;
                return 0;
            }break;
        }
        cout << endl;
        cout << "������Ҫ���еĲ���:";
        cin >> command;
    }
    return 0;
}


