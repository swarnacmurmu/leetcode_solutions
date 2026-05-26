class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        pair<int, int> src = {0, 0};
        pair<int, int> dest = {n - 1, n - 1};
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        q.push({1, {0, 0}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == n - 1 && c == n - 1)
            {
                return dis;
            }

            // for 8 directions
            for (int delr = -1; delr <= 1; delr++)
            {
                for (int delc = -1; delc <= 1; delc++)
                {
                    int newr = r + delr;
                    int newc = c + delc;
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc])
                    {
                        dist[newr][newc] = 1 + dis;

                        q.push({1 + dis, {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
};