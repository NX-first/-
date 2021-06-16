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
//��ʼ������
QElemType InitQueue(SeqQueue &Q){
    Q.data=(QElemType *)malloc(MAXQSIZE *sizeof(QElemType));//����ն���
    if(!Q.data)exit(OVERFLOW);
    Q.rear = Q.front = 0;
    return OK;
}
//�������� 
QElemType CreatQueue(SeqQueue &Q){
    cout << "������е�Ԫ��(��'-1'����):";
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
    cout << "����ɹ���" << endl;
    return OK;
}

int DeQueue(SeqQueue &Q){
    if (Q.rear == Q.front) return 0;
	Q.front = ( Q.front+1) % MAXQSIZE;
	cout << "ɾ���ɹ���" << endl;
	return OK;
}

int PrintQueue (SeqQueue &Q) {
    if (Q.rear == Q.front)
    {
        cout << "�ն���!" << endl;
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
    cout << "1:����һ��ѭ������" << endl;
    cout << "2:���ض��г���" << endl;
    cout << "3:����Ԫ��" << endl;
    cout << "4:ɾ��Ԫ��" << endl;
    cout << "5:��������е�Ԫ��" << endl;
    cout << "6:�˳�" << endl;
    cout << endl;


    int command = 0;
    cout << "������Ҫ���еĲ���:";
    cin >> command;

    while(command != 1 && command != 6){ //Ҫô����ջ��Ҫô�˳���������Ϊ�Ƿ�����
        cout << "��δ����ջ��/�Ƿ����룡" <<endl;
        cout << "������Ҫ���еĲ���:";
        cin >> command;
    }
    if (command == 6) {
        cout << "�˳�����!" << endl;
        return 0;
    }

    SeqQueue Q;
    InitQueue (Q);
    QElemType e;
    while(command != 6){
        if (command < 1 || command > 6){
            cout << "�Ƿ����룡" << endl;
        }
        switch(command){
            case 1 :{
                CreatQueue(Q);
                cout << "�Ѵ����ɹ���" << endl;
            }break;

            case 2 :{
                cout << "���г���Ϊ:";
                QueueLength(Q);
                cout << endl;
            }break;

            case 3 :{
                cout << "������Ҫ�����Ԫ��:";
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


