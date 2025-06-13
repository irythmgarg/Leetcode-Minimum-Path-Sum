# Leetcode-Minimum-Path-Sum

# Minimum Path Sum

## 🤩 Problem Statement

Given a `m x n` grid filled with non-negative numbers, find a path from the top-left corner to the bottom-right corner which minimizes the **sum of all numbers** along its path.

You can only move either **down** or **right** at any point in time.

---

## 🔪 Example

**Input:**

```cpp
grid = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1]
]
```

**Output:**

```
7
```

**Explanation:**
Path → `1 → 3 → 1 → 1 → 1` = 7 (minimum sum path)

---

## 🚀 Approaches

### 1. 🤭 Dijkstra's Algorithm Approach (Using Min Heap)

* Treat the grid as a graph where each cell is a node.
* Use a min-heap (priority queue) to greedily choose the path with the smallest cumulative cost.
* Move only right or down.
* Stop when the destination cell `(m-1, n-1)` is reached.

```cpp
int minPathSum(vector<vector<int>>& grid) {
    using p = pair<int, pair<int, int>>;
    int m = grid.size(), n = grid[0].size();
    priority_queue<p, vector<p>, greater<p>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    q.push({grid[0][0], {0, 0}});

    while (!q.empty()) {
        auto [cost, pos] = q.top(); q.pop();
        int i = pos.first, j = pos.second;
        if (visited[i][j]) continue;
        if (i == m - 1 && j == n - 1) return cost;
        visited[i][j] = true;
        if (i + 1 < m) q.push({cost + grid[i + 1][j], {i + 1, j}});
        if (j + 1 < n) q.push({cost + grid[i][j + 1], {i, j + 1}});
    }
    return -1;
}
```

**Time Complexity:** `O(m * n * log(mn))`

**Space Complexity:** `O(m * n)`

---

### 2. 📊 Dynamic Programming (Bottom-Up Tabulation)

* Build a DP table `dp[i][j]` to store the minimum path sum from `(0,0)` to `(i,j)`.
* Initialize the first row and first column as they have only one possible path.
* Fill the rest using:

  ```
  dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
  ```

```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[m-1][n-1];
}
```

**Time Complexity:** `O(m * n)`

**Space Complexity:** `O(m * n)` (can be optimized to `O(n)`)

---

## ✍️ Author

**Ridham Garg**
B.Tech Computer Engineering
Thapar University, Patiala
Roll No: 102203014
