#include <iostream>
#define MAXVEX 3      //结点数（初始默认3顶点，更改的话直接在这里修改即可）
#define MAXEDGE 5     //边数（初始默认5条边，更改的话直接在这里修改即可）
#define INFINITY 65535 //表示无穷大
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
        cout<<"请输入第"<<i<<"个结点的信息：";
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
        cout<<"请输入第"<<i<<"条边的信息（形如A B 7,表示从A到B的一条边权值7）：";
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
                    pre[v][w]=pre[v][k];//路径设置经过下标为k的顶点
                }
            }
        }
    }
}
void ShowFloyd(AdjMatr &g, int dist[MAXVEX+1][MAXVEX+1],int pre[MAXVEX+1][MAXVEX+1])
{
    cout<<"弗洛伊德算法多源最短路径如下："<<endl;
    for(int v=1;v<=MAXVEX;v++)
    {
        for(int w=v+1;w<=MAXVEX;w++) 
        {
            cout<<g.vexinfo[v]<<"->"<<g.vexinfo[w]<<"最短路径长度："<<dist[v][w]<<"     ";
            cout<<"具体路径为："<<g.vexinfo[v];
            int k=pre[v][w];  
            while(k != w) 
            {
                cout<<"->"<<g.vexinfo[k]; 
                k=pre[k][w];       
            }
            cout<<"->"<<g.vexinfo[w]<<endl; //打印终点
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
    cout<<"dist数组："<<endl;
    for(int i=1;i<=MAXVEX;i++)
    {
        for(int j=1;j<=MAXVEX;j++)
        {
            cout<<dist[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"pre数组："<<endl;
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
