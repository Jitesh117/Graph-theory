#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    cout << "Enter vertices and their weights: ";
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    bool mstset[n];
    int parent[n], key[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        key[i] = INT_MAX;
        mstset[i] = false;
    }
    key[0] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int mini = INT_MAX, u;
        for (int i = 0; i < n; i++)
        {
            if (mstset[i] == false and key[i] < mini)
            {
                mini = key[i], u = i;
            }
        }
        mstset[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstset[v] == false and weight < key[v])
            {
                parent[v] = u, key[v] = weight;
            }
        }
    }
    cout << "The MST is: \n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " -> "<< i << endl;
    return 0;
}