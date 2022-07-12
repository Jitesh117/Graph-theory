#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, source;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1]; // 1 indexed adjacency list for graph representation
    cout << "Enter weights of the edges: ";
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }
    cout << "Enter source node: ";
    cin >> source;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int prev = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for (auto it = g[prev].begin(); it != g[prev].end(); it++)
        {
            int next = it->first;
            int nextdist = it->second;
            if (dist[next] > dist[prev] + nextdist)
            {
                dist[next] = dist[prev] + nextdist;
                pq.push({dist[next], next});
            }
        }
    }
    cout << "The distance from the source are: ";
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}