#include <iostream>
using namespace std;

#define MaxVertexNum 10
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

bool Visited[MaxVertexNum]={false};

typedef struct ENode{
    Vertex V1,V2;
    WeightType Weight;
}*Edge;

typedef struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data;
}*MGraph;

MGraph BuildGraph(int n,int m);
MGraph CreateGraph(int n);
void InsertGraph(MGraph Graph,Edge E);
void DFS(MGraph Graph,Vertex V);
void BFS(MGraph Graph,Vertex V);
void Visit(Vertex V);

int main(){
    int n,m;
    cin>>n>>m;
    MGraph Graph=BuildGraph(n,m);
    DFS(Graph,0);
    BFS(Graph,0);
}

MGraph BuildGraph(int n,int m){
    MGraph Graph=CreateGraph(n);
    Graph->Ne=m;
    if(Graph->Ne){
        Edge E=new ENode;
        for(int i=0;i<Graph->Ne;i++){
            cin>>E->V1>>E->V2;
            InsertGraph(Graph, E);
        }
    }
    
    return Graph;
}

MGraph CreateGraph(int n){
    MGraph Graph=new GNode;
    Graph->Nv=n;
    Graph->Ne=0;
    
    for(Vertex V=0;V<Graph->Nv;V++)
        for(Vertex W=0;W<Graph->Nv;W++)
            Graph->G[V][W]=0;
    
    return Graph;
}

void InsertGraph(MGraph Graph,Edge E){
    Graph->G[E->V1][E->V2]=1;
    Graph->G[E->V2][E->V1]=1;
}

void DFS(MGraph Graph,Vertex V){
    Visit(V);
    Visited[V]=true;
    
    for(Vertex W=0;W<Graph->Nv;W++){
        if(!Visited[W])
            DFS(Graph,W);
    }
}
/*
2-0-7
| |
4-1
3-5
6
*/
