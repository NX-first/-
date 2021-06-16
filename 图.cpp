#include <iostream>
#define MAXVEX 3      //���������ʼĬ��3���㣬���ĵĻ�ֱ���������޸ļ��ɣ�
#define MAXEDGE 5     //��������ʼĬ��5���ߣ����ĵĻ�ֱ���������޸ļ��ɣ�
#define INFINITY 65535 //��ʾ�����
using namespace std;
typedef struct
{
    int  vexNum;
    int  edgeNum;
    int  matrix[MAXVEX+1][MAXVEX+1];
    char vexinfo[MAXVEX+1];
}AdjMatr;
void initAdjMatr(AdjMatr &g )
{
    g.vexNum = MAXVEX;  
    g.edgeNum = MAXEDGE;
    for(int i=1;i<=MAXVEX;i++)
    {
        for(int j=1;j<=MAXVEX;j++)
        {
            if(i == j)
                g.matrix[i][j]=0;
            else
                g.matrix[i][j]=INFINITY;
        }
    }
    for(int i=1;i<=MAXVEX;i++)
    {
        cout<<"�������"<<i<<"��������Ϣ��";
        cin>>g.vexinfo[i];
    }
}
void locata(AdjMatr &g,char &vex1,char &vex2, int &m, int &n)
{
    for(int i =1;i<=MAXVEX;i++)
    {
        if(vex1 == g.vexinfo[i])
            m=i;
        if(vex2 == g.vexinfo[i])
            n=i;
    }
}
void setAdjMatr(AdjMatr &g)
{
     for(int i=1;i<=g.edgeNum;i++)
    {
        int weight;
        char vex1,vex2; 
        cout<<"�������"<<i<<"���ߵ���Ϣ������A B 7,��ʾ��A��B��һ����Ȩֵ7����";
        cin>>vex1>>vex2>>weight;
        int m,n;
        locata(g,vex1,vex2,m,n);
        g.matrix[m][n]=weight;
        g.matrix[n][m]=weight;
    }
}
void Floyd(AdjMatr &g, int dist[MAXVEX+1][MAXVEX+1],int pre[MAXVEX+1][MAXVEX+1])
{
    for(int i=1;i<=MAXVEX;i++)
    {
        for(int j=1;j<=MAXVEX;j++)
        {
            dist[i][j]=g.matrix[i][j]; 
            pre[i][j]=j;
        }
    }
    for(int k=1;k<=MAXVEX;k++)
    {
        for(int v=1;v<=MAXVEX;v++)
        {
            for(int w=1;w<=MAXVEX;w++)
            {
                if(dist[v][w]>dist[v][k]+dist[k][w])
                {
                    dist[v][w]=dist[v][k]+dist[k][w];
                    pre[v][w]=pre[v][k];//·�����þ����±�Ϊk�Ķ���
                }
            }
        }
    }
}
void ShowFloyd(AdjMatr &g, int dist[MAXVEX+1][MAXVEX+1],int pre[MAXVEX+1][MAXVEX+1])
{
    cout<<"���������㷨��Դ���·�����£�"<<endl;
    for(int v=1;v<=MAXVEX;v++)
    {
        for(int w=v+1;w<=MAXVEX;w++) 
        {
            cout<<g.vexinfo[v]<<"->"<<g.vexinfo[w]<<"���·�����ȣ�"<<dist[v][w]<<"     ";
            cout<<"����·��Ϊ��"<<g.vexinfo[v];
            int k=pre[v][w];  
            while(k != w) 
            {
                cout<<"->"<<g.vexinfo[k]; 
                k=pre[k][w];       
            }
            cout<<"->"<<g.vexinfo[w]<<endl; //��ӡ�յ�
        }
    }
    cout<<endl;
}
int main()
{
    AdjMatr g;
    initAdjMatr(g);
    setAdjMatr(g);
    int dist[MAXVEX+1][MAXVEX+1];
    int pre[MAXVEX+1][MAXVEX+1]; 
    Floyd(g,dist,pre);
    ShowFloyd(g,dist,pre);  
    cout<<"dist���飺"<<endl;
    for(int i=1;i<=MAXVEX;i++)
    {
        for(int j=1;j<=MAXVEX;j++)
        {
            cout<<dist[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"pre���飺"<<endl;
    for(int i=1;i<=MAXVEX;i++)
    {
        for(int j=1;j<=MAXVEX;j++)
        {
            cout<<g.vexinfo[pre[i][j]]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
