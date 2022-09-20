//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] and grid[i][j] == '1')
                {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        return count;
    }
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});

        while (q.size())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse in the neighbors and mark them if it's a land
            for (int delrow = -1; delrow <= 1; delrow++)
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == '1' and !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
        }
    }
};
