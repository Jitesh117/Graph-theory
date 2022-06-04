#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout <<"Enter the number of nodes and edges:";
    cin >> n >> m;
    cout <<"Enter the vertices and weights: \n";
    vector<pair<int,int>> adj[n];
    int a,b,wt;
    // for(int i = 0;i<m;i++)
    // {
    //     cin >> a >> b >> wt;
    //     adj[a].push_back(make_pair(b,wt));
    //     adj[b].push_back(make_pair(a,wt));  
    // }
    adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
    int parent[n];
    bool mstSet[n];
    int key[n];

    for (int i = 0; i < n; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < n - 1; count++)
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < n; v++) 
{
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
}
                 mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 1; i < n; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}