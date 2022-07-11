#include<bits/stdc++.h>
using namespace std;
bool bipartitieBFS(int src,vector<int>adj[],int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                q.push(it);
                color[it] = 1 - color[node];
            }
            else if(color[it] == color[node])
                return false;
        }
    }
    return true;
}
bool checkbipartite(vector<int>adj[],int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n;i++)
        if(color[i] == -1)
            if(!bipartitieBFS(i,adj,color))
                return false;
    return true;
}