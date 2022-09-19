#include <bits/stdc++.h>
using namespace std;
int parent[100000];
int rank[100000];

void makeset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;    
    }
}
int findpar(int node)
{
    if(parent[node] == node)
        return node;
    return parent[node] = findpar(parent[node]);  //path compression
}

int main()
{
    int n;
    cin >> n;
    makeset(n);

}