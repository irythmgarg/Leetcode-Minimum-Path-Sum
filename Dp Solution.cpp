class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();        // Number of rows
        int n = grid[0].size();     // Number of columns

        // Create a DP table to store the minimum path sum at each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the starting cell
        dp[0][0] = grid[0][0];

        // Fill the first column (can only come from the top)
        int prev = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + prev;
            prev = dp[i][0];
        }

        // Fill the first row (can only come from the left)
        prev = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = grid[0][i] + prev;
            prev = dp[0][i];
        }

        // Fill the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Minimum path to (i,j) is from either the top or the left cell
                dp[i][j] = min(dp[i - 1][j] + grid[i][j],
                               dp[i][j - 1] + grid[i][j]);
            }
        }

        // Return the minimum path sum to reach bottom-right cell
        return dp[m - 1][n - 1];
    }
};
