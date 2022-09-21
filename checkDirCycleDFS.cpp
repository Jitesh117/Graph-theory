#include <bits/stdc++.h>
using namespace std;
bool checkcycle(int source, vector<int> vis, vector<int> dfsvis, vector<int> adj[])
{
    vis[source] = 1;
    dfsvis[source] = 1;
    for (auto it : adj[source])
    {
        if (!vis[it])
        {
            if (checkcycle(it, vis, dfsvis, adj))
                return true;
        }
        else if (dfsvis[it])
            return true;
    }
    dfsvis[source] = 0;
    return false;
}
bool iscycle(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    vector<int> dfsvis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            if (checkcycle(i, vis, dfsvis, adj))
                return true;
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> adj[] = {{}, {2}, {3}, {4, 6}, {5}, {}, {5}, {2, 8}, {9}, {7}};
    if (iscycle(n, adj))
        cout << "Cycle detected";
    else
        cout << "No cycle";
    return 0;
}