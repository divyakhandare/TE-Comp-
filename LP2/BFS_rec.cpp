#include<iostream>
#include<queue>
using namespace std;
class Graph
{
    public:
        int **graph;
        int n;
        bool dir,wt;
        int start;
        Graph()
        {
            n = 0;
            graph = NULL;
        }

        void creategraph()
        {
            cout<<"\nEnter number of vertices = ";
            cin>>n;
            cout<<"Is it directed?";
            cin>>dir;
            cout<<"Is it weighted?";
            cin>>wt;
            cout<<"Enter start = ";
            cin>>start;
            graph = new int*[n];
            int i,j;
            for(i = 0;i<n;i++)
            {
                graph[i] = new int[n];
            }
            for(i = 0;i<n;i++)
            {
                for(j = 0;j<n;j++)
                {
                    graph[i][j] = 0;
                }
            }
        }
        void readgraphmat()
        {
            cout<<"\nEnter matrix = \n";
            int i,j;
            for(i = 0;i<n;i++)
            {
                for(j = 0;j<n;j++)
                {
                    cin>>graph[i][j];
                }
            }
        }
        void readgraphedge()
        {
            int u,v,w;
            cout<<"\nEnter (u,v,w) or (-1,-1) to stop: \n";
            while (true)
            {
                cin>>u>>v;
                if(u == -1 || v == -1)
                {
                    break;
                }
                insert_edge(u,v);
                if(dir == false)
                {
                	insert_edge(u,v);
				}
                
            }
        }
        void insert_edge(int u,int v)
        {
            graph[u][v] = 1;
        }
        void printgraph()
        {
            cout<<"\nGraph: \n";
            int i,j;
            for(i = 0;i<n;i++)
            {
                for(j = 0;j<n;j++)
                {
                    cout<<graph[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void BFS()
        {
        	queue<int> que;
        	int *visited = new int[n];
        	int i;
        	int v;
        	cout<<"\nEnter start = ";
        	cin>>v;
        	for(i = 0;i<n;i++)
        	{
        		visited[i] =0;
			}
			cout<<"\nvisited "<<v;
			visited[v] =1;
			que.push(v);
			while(que.empty() == 0)
			{
				v = que.front();
				que.pop();
				for(i = 0;i<n;i++)
				{
					if(graph[v][i] != 0 && visited[i] == 0)
					{
						cout<<"\nvisited "<<i;
						visited[i] = 1;
						que.push(i);
					}
				}
			}
		}
};
int main()
{
    Graph g;
    g.creategraph();
    g.readgraphmat();
    cout<<"\nBFS traversal = ";
    g.BFS();
    return 0;
}
