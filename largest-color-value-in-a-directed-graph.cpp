class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // first we need a topological sort
        int n = colors.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            dp[i][colors[i] - 'a'] = 1;
        }
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!indegree[i])
                q.push(i);
        int c = 0, ans = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            c++;
            for (int i = 0; i < 26; i++)
                ans = max(ans, dp[node][i]);
            for (auto i : adj[node]) {
                for (int j = 0; j < 26; j++) {
                    int x = (colors[i] - 'a' == j) ? 1 : 0;
                    dp[i][j] = max(dp[i][j], dp[node][j]+x);
                }
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        if (c != n)
            return -1;
        return ans;
    }
};
//so basically we need to think of the max freq of colors in all the possible paths
/*
dp[node][c] stores the max freq of color c till node 
so we do topo sort and then do max(freq of that color if we go thru the current path, original max freq)
we do topo so that we always mode in direction of u -> v
one doubt i had was since i initialised dp[node][s[node]-'a] = 1
won't we be double counting in 
for (int j = 0; j < 26; j++) {
                    int x = (colors[i] - 'a' == j) ? 1 : 0;
                    dp[i][j] = max(dp[i][j], dp[node][j]+x);
                }
Ans: original max freq = dp[i][j]
new max freq = dp[node][color] + 1(if the neighbor has the same color)

*/
