#include<iostream>
using namespace std;
class Graph
{
    public:
        int **graph;
        int n;
        bool wt,dir;
        Graph()
        {
            cout<<"\nEnter number of vertices = ";
            cin>>n;
            cout<<"If directed = ";
            cin>>dir;
            cout<<"If weighted = ";
            cin>>wt;
            graph = new int*[n];
            int i,j;
            for(i = 0;i<n;i++)
            {
                graph[i] = new int [n];
            }
            for(i = 0;i<n;i++)
            {
                for(j = 0;j<n;j++)
                {
                    graph[i][j] = 0;
                }
            }
        }
        void readgraphedge()
        {
            int u,v;
            cout<<"\nEnter edge (u,v) or (-1,-1) to stop";
            while (true)
            {
                cin>>u>>v;
                if(u == -1 || v == -1)
                {
                    break;
                }
                insertedge(u,v);
                if(dir == 0)
                {
                    insertedge(v,u);
                }
            }
        }
        void insertedge(int u, int v)
        {
            graph[u][v] = 1;
        }
        void traversal()
        {
            int *visited;
            visited = new int[n];
            int i;
            for(i = 0;i<n;i++)
            {
                visited[i] = 0;
            }
            int v;
            cout<<"\nEnter starting vertex =";
            cin>>v;
            cout<<"Component 1: ";
            DFS_rec(visited, v);
            int count = 1;
            for(i = 0;i<n;i++)
            {
                if(visited[i] == 0)
                {
                    cout<<"\nComponent "<<count+1<<": ";
                    count++;
                    DFS_rec(visited,i);
                }
            }
        }
        void DFS_rec(int *visited,int vertex)
        {
            visited[vertex] = 1;
            cout<<vertex<<" ";
            int i;
            for(i = 0;i<n;i++)
            {
                if(graph[vertex][i] != 0)
                {
                    if(visited[i] == 0)
                    {
                        DFS_rec(visited, i);
                    }
                }
            }
        }
};
int main()
{
    Graph g;
    g.readgraphedge();
    g.traversal();
    return 0;
}
