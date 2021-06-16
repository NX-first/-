#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXQSIZE 100
typedef int QElemType;
typedef struct{
	QElemType *data;
	int front;      
	int rear;       
} SeqQueue;
//初始化队列
QElemType InitQueue(SeqQueue &Q){
    Q.data=(QElemType *)malloc(MAXQSIZE *sizeof(QElemType));//构造空队列
    if(!Q.data)exit(OVERFLOW);
    Q.rear = Q.front = 0;
    return OK;
}
//创建队列 
QElemType CreatQueue(SeqQueue &Q){
    cout << "输入队列的元素(以'-1'结束):";
    int Queue[MAXQSIZE];
    int i = 0;
    while (cin >> Queue[i] && Queue[i] != -1){
        i ++;
    }
    int j = 0;
    while (Queue[j] != -1){
        Q.data[Q.rear] = Queue[j];
        Q.rear = ( Q.rear+1) % MAXQSIZE;
        j ++;
    }
    return OK;
}

void QueueLength(SeqQueue &Q){
    cout << (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}


int EnQueue(SeqQueue &Q, QElemType &e){
    if ((Q.rear+1) % MAXQSIZE == Q.front) return ERROR;
    Q.data[Q.rear] = e;
    Q.rear = ( Q.rear+1) % MAXQSIZE;
    cout << "插入成功！" << endl;
    return OK;
}

int DeQueue(SeqQueue &Q){
    if (Q.rear == Q.front) return 0;
	Q.front = ( Q.front+1) % MAXQSIZE;
	cout << "删除成功！" << endl;
	return OK;
}

int PrintQueue (SeqQueue &Q) {
    if (Q.rear == Q.front)
    {
        cout << "空队列!" << endl;
        return ERROR;
    }
    int i = Q.front;
    while (i!=Q.rear)
    {
        cout << Q.data[i] << " ";
        i = (i + 1) % MAXQSIZE;
    }
    cout << endl;
    return OK;
}

int main()
{
    cout << "1:创建一个循环队列" << endl;
    cout << "2:返回队列长度" << endl;
    cout << "3:插入元素" << endl;
    cout << "4:删除元素" << endl;
    cout << "5:输出队列中的元素" << endl;
    cout << "6:退出" << endl;
    cout << endl;


    int command = 0;
    cout << "请输入要进行的操作:";
    cin >> command;

    while(command != 1 && command != 6){ //要么创建栈，要么退出，否则即视为非法输入
        cout << "还未创建栈！/非法输入！" <<endl;
        cout << "请输入要进行的操作:";
        cin >> command;
    }
    if (command == 6) {
        cout << "退出程序!" << endl;
        return 0;
    }

    SeqQueue Q;
    InitQueue (Q);
    QElemType e;
    while(command != 6){
        if (command < 1 || command > 6){
            cout << "非法输入！" << endl;
        }
        switch(command){
            case 1 :{
                CreatQueue(Q);
                cout << "已创建成功！" << endl;
            }break;

            case 2 :{
                cout << "队列长度为:";
                QueueLength(Q);
                cout << endl;
            }break;

            case 3 :{
                cout << "请输入要插入的元素:";
                cin >> e;
                EnQueue(Q, e);
            }break;

            case 4 :{
                DeQueue(Q);
            }break;

            case 5 :{
                PrintQueue(Q);
            }break;

            case 6 :{
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


