#include <bits/stdc++.h>
using namespace std;

bool checkcycle(int v, vector<int> adj[])
{

    vector<int> dfsvis(v, 0);
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i, dfsvis, vis, v, adj))
                return true;
        }
        return false;
    }
}

bool isCycle(int source, vector<int> &dfsvis, vector<int> &vis, int v, vector<int> adj[])
{
    dfsvis[source] = 1;
    vis[source] = 1;

    for (auto i : adj[source])
    {
        if (!vis[i])
        {
            if (isCycle(i, dfsvis, vis, v, adj))
                return true;
        }
        else if (dfsvis[i])
        {
            return true;
        }

    }
    dfsvis[source] = 0;
    return false;
}