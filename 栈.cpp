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
}//初始化栈
void creatstack(SqStack &S){
    int stacklength;
    cout << "请输入栈的长度:";
    cin >> stacklength;
    if (S.top - S.base >= stacklength) {
        cout << "非法长度！" << endl;
    }
    int StackElem[stack_init_size];
    for (int i = 0; i < stack_init_size; i++){
        StackElem[i] = -1;
    }
    cout << "输入创建的栈元素:";
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
			cout << "入栈操作失败！" << endl;
			return ERROR;
		}
		S.top = S.base + S.SSize;
		S.SSize += stackincreament;
	}
	*S.top++ = e;
	cout << "入栈操作成功！" << endl;
	return OK;
}
Status pop(SqStack &S, SElemType &e) {
	if (S.base == S.top){
		cout << "出栈操作失败！" << endl;
		return ERROR;
	}
	e = *--S.top;
	cout << "出栈操作成功！" << endl;
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
    cout << "1:创建一个栈" << endl;
    cout << "2:入栈操作" << endl;
    cout << "3:出栈操作" << endl;
    cout << "4:输出栈元素" << endl;
    cout << "5:退出" << endl;

    int command = 0;
    cout << "请输入要进行的操作:";
    cin >> command;

    while(command != 1 && command != 5){ //要么创建栈，要么退出，否则即视为非法输入
        cout << "还未创建栈！/非法输入！" <<endl;
        cout << "请输入要进行的操作:";
        cin >> command;
    }
    if (command == 5) {
        cout << "退出程序!" << endl;
        return 0;
    }
	SqStack S;
	initstack(S);
    creatstack(S);
    SElemType e;
    while(command != 5){
        if (command < 1 || command > 6){
            cout << "非法输入！" << endl;
        }
        switch(command){
            case 1 :{
                cout << "已创建成功！" << endl;
            }break;

            case 2 :{
                cout << "输入入栈元素:";
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
                cout << "退出程序!" << endl;
                return 0;
            }break;
        }
        cout << endl;
        cout << "请输入要进行的操作:";
        cin >> command;
    }
    return 0;
}


