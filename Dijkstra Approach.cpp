class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        using p = pair<int, pair<int, int>>;  // Define a type alias for a pair: {cost, {i, j}}

        int m = grid.size();      // Number of rows
        int n = grid[0].size();   // Number of columns

        // Min-heap (priority queue) to always process the least cost cell first
        priority_queue<p, vector<p>, greater<p>> q;

        // Start from the top-left corner (0,0) with initial cost grid[0][0]
        q.push({grid[0][0], {0, 0}});

        // Visited array to prevent revisiting cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while (!q.empty()) {
            int topcost = q.top().first;         // Total path cost to reach this cell
            int topi = q.top().second.first;     // Row index
            int topj = q.top().second.second;    // Column index
            q.pop();

            // Skip if already visited
            if (visited[topi][topj])
                continue;

            // If destination cell is reached, return the cost
            if (topi == m - 1 && topj == n - 1)
                return topcost;

            // Mark current cell as visited
            visited[topi][topj] = true;

            // Move Down
            if (topi + 1 < m && !visited[topi + 1][topj]) {
                q.push({topcost + grid[topi + 1][topj], {topi + 1, topj}});
            }

            // Move Right
            if (topj + 1 < n && !visited[topi][topj + 1]) {
                q.push({topcost + grid[topi][topj + 1], {topi, topj + 1}});
            }
        }

        // Return -1 in case the destination is not reachable (not expected here)
        return -1;
    }
};
