#include <bits/stdc++.h>
using namespace std;
bool isbipartite(int src, vector<int> color, vector<vector<int>> &adj)
{
    if (color[src] == -1)
        color[src] = 1;
    for (auto it : adj[src])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[src];
            if (!isbipartite(it, color, adj))
                return false;
        }
        else if (color[it] == color[src])
            return false;
    }
    return true;
}
bool bipartite(vector<vector<int>> &adj, int n)
{
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
            if (isbipartite(i, color, adj) == false)
                return false;
    }
    return true;
}
