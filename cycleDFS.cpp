#include <bits/stdc++.h>
using namespace std;
bool checkcycle(int src, int par, vector<int> vis, vector<int> adj[])
{
    vis[src] = 1;
    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            if (checkcycle(it, src, vis, adj))
                return true;
        }
        else if (it != par)
            return true;
    }
    return false;
}
bool iscycle(int n, vector<int> adj[])
{
    vector<int> vis(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            if (checkcycle(i, -1, vis, adj))
                return true;
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> adj[] = {{}, {3}, {5}, {1, 4}, {3}, {2, 6, 8}, {5, 7}, {6, 8}, {5, 7}};
    // vector<int> adj[] = {{}, {3}, {5}, {1, 4}, {3}, {2, 6, 8}, {5, 7}, {6}, {5}};
    if (iscycle(n, adj))
        cout << "yes";
    else
        cout << "NO";
    return 0;
}
