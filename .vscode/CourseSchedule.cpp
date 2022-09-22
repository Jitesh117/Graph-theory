#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        queue<int> zerodegree;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                zerodegree.push(i);
                n--;
            }
        }

        while (zerodegree.size())
        {
            int node = zerodegree.front();
            zerodegree.pop();

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    zerodegree.push(it);
                    n--;
                }
            }
        }
        return n == 0;
    }
};