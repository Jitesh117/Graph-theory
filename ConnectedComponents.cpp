#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][j] == 1 and i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
            if (!vis[i])
            {
                count++;
                dfs(i, vis, adj);
            }
        return count;
    }

    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
            if (!vis[it])
                dfs(it, vis, adj);
    }
};