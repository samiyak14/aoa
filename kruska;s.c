#include <stdio.h>

#define V 6
#define E 9  // number of edges (update if you add/remove edges)

struct Edge {
    int src, dest, weight;
};

// Sample graph with 6 vertices and 9 edges
struct Edge edges[E] = {
    {0, 1, 2},
    {0, 5, 4},
    {1, 2, 8},
    {1, 5, 3},
    {2, 3, 6},
    {2, 4, 1},
    {3, 4, 12},
    {4, 5, 2},
    {5, 1, 3}  // Duplicate edge direction (optional)
};
int parent[V];

int find(int i)
{
    while(parent[i]!=i)
    {
        i=parent[i];
    }
    return i;
}

void unionSet(int i, int j)
{
    int a=find(i);
    int b=find(j);
    parent[a]=b;
}

void sortEdges()
{
    struct Edge temp;
    for(int i=0;i<E-1;i++)
    {
        for(int j=0;j<E-i-1;j++)
        {
            if(edges[j].weight>edges[j+1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;

            }
        }
    }
}

void kruskal()
{
    struct Edge result[V-1];
    int count=0;
    sortEdges();
     for(int i=0;i<V;i++)
     {
         parent[i]=i;
     }
     for(int i=0;i<E && count<V-1;i++)
     {
        int u=edges[i].src;
        int v=edges[i].dest;
        
        int set_u=find(u);
        int set_v=find(v);
        
        if(set_u!=set_v)
        {
            result[count++]=edges[i];
            unionSet(set_u, set_v);
        }
     }
     printf("Edge\tWeight\n");
    for (int i = 0; i < count; i++) {
        printf("%d - %d\t%d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    kruskal();
    return 0;
}
