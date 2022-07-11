#include <bits/stdc++.h>
using namespace std;
bool checkcycle(int s, int V, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({s, -1});
    vis[s] = 1;
    while(!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push({it, node});
                vis[it] = 1;
            }
            else if(it!=par)
                return true;
        }
    }
}
bool iscycle(int V, vector<int> adj[], vector<int> &vis)
{
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (checkcycle(i, V, adj, vis))
                return true;
        }
    }
    return false;
}
int main()
{
    cout << "Enter the size of the graph:";
    int n;
    cin >> n;
    vector<int> adj[] = {{0}, {2}, {1, 4, 7}, {5}, {2, 6}, {3}, {4, 7}, {2, 6}};
    vector<int> vis(n + 1, 0);
    if(iscycle(n,adj,vis))
        cout << "Cycle detected";
    else
        cout << "No cycle detected.";
    return 0;
}