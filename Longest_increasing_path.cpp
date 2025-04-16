class Solution {
public:
    int n, m;
    bool isValid(int r, int c) { return r >= 0 and c >= 0 and r < n and c < m; }
    int dfs(vector<vector<int>>& v, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int ans = 0;
        for (auto x : dir) {
            int nr = i + x[0], nc = j + x[1];
            if (isValid(nr, nc) and v[nr][nc] > v[i][j]) {
                ans = max(ans, dfs(v, dp, nr, nc) + 1);
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& v) {
        n = v.size(), m = v[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(dp[i][j] == -1)
                res = max(res, dfs(v, dp, i, j)+1);
            }
        }
        return res;
    }
};
