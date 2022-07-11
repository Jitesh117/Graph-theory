#include <bits/stdc++.h>
using namespace std;
bool checkcycle(int node, vector<int> vis, vector<int> dfsvis, vector<int> adj[])
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkcycle(it, vis, dfsvis, adj))
                return true;
        }
        else if (dfsvis[it])
            return true;
    }
    dfsvis[node] = 0;
    return false;
}
bool cycle(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    vector<int> dfsvis(n, 0);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            if (checkcycle(i, vis, dfsvis, adj))
                return true;
    return false;
}