#include <bits/stdc++.h>
using namespace std;
void toposort(int node, stack<int> st, vector<int> vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            toposort(it, st, vis, adj);
    }
    st.push(node);
}
vector<int> toposortDFS(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            toposort(i, st, vis, adj);
    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}