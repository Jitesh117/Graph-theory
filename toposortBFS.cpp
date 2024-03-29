// First step: write down the in-degree of each node
// Use a queue to store the nodes whose indegree is zero
// reduce the indegree of each adjacent node 
// keep removing the nodes which have indegree = 0
#include <bits/stdc++.h>
using namespace std;
vector<int> toposortBFS(int n, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}