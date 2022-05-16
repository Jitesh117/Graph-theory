#include<bits/stdc++.h>
using namespace  std;
class solution{
    public:
        vector<int> bfsofgraph(int V, vector<int> adj[])
        {
            vector<int> bfs;
            vector<int> vis(V+1,0);


            for(int i = 1;i<=V;i++)
            {
                if(!vis[i])
                {
                    queue<int> q;
                    q.push(i);
                    vis[i] = 1;
                    while(!q.empty())
                    {
                        int node = q.front();
                        q.pop();
                        bfs.push_back(node);

                        for(auto it: adj[node])
                        {
                            if(!vis[it])
                            {
                                q.push(it);
                                vis[it] = 1;
                            }
                        }
                    }
                }
            }
         return bfs;

        }
};
vector<int> bfsofgraph(int V, vector<int> adj[])
        {
            vector<int> bfs;
            vector<int> vis(V+1,0);


            for(int i = 1;i<=V;i++)
            {
                if(!vis[i])
                {
                   queue<int> q;
                   q.push(i);
                  
                   while(!q.empty())
                   {
                       int node = q.front();
                       q.pop();
                        bfs.push_back(node);
                       for(auto it: adj[node])
                       {
                           if(!vis[it])

                           {
                               vis[it] = 1;
                               q.push(it);
                           }
                       }
                   }
                }
            }
         return bfs;

        }
int main()
{
    cout <<"Enter the size of the graph:";
    int n;
    cin>> n;
    vector<int> adj[]={{0},{2},{1,4,7},{5},{2,6},{3},{4,7},{2,6}};
    vector<int> result = bfsofgraph(n,adj);
    for(auto it: result)
    {
        cout << it << " ";
    }

    return 0;
}