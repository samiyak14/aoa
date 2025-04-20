#include <stdio.h>
#define INFINITY 9999
#define V 6

int minKey(int mstSet[],int key[])
{
  int min=INFINITY, min_index=-1;
  for(int v=0;v<V;v++)
  {
    if(mstSet[v]==0 && key[v]<min)
    {
      min=key[v];
      min_index=v;
    }
  }
  return min_index;
}

void printMST(int parent[], int graph[V][V])
{
  printf("Edge\tWeight\n");
  for(int i=1;i<V;i++)
  {
    printf("%d-%d\t%d\n",parent[i],i,graph[i][parent[i]]);
  }
}

int prims(int graph[V][V])
{
  int parent[V],key[V],mstSet[V];
  //initialising key and mstSet
  for (int i=0;i<V;i++ )
  {
    key[i]=INFINITY;
    mstSet[i]=0;
  }
  
  //setting distance of source=0 and parent of osurce to -1
  key[0]=0;
  parent[0]=-1;
  
  for(int count=0;count<V-1;count++)
  {
    int u=minKey(mstSet,key); //get minimum ode from unvisited nodes
    mstSet[u]=1;
    for(int v=0;v<V;v++) //check which edge is minimum and add it to the mst
    {
    if(graph[u][v] && mstSet[v]==0 && graph[u][v]<key[v])
    {
      parent[v]=u;
      key[v]=graph[u][v];
    }
    }
  }
  printMST(parent,graph);
  return 0;
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 0, 0, 4},
        {2, 0, 8, 0, 0, 3},
        {0, 8, 0, 6, 1, 0},
        {0, 0, 6, 0, 12, 0},
        {0, 0, 1, 0, 12, 0},
        {4, 3, 0, 0, 2, 0}};
        
    prims(graph);
    return 0;
}
