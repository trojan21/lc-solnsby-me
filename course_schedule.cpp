class Solution {
public:
bool dfs(vector<vector<int>> &v, vector<int> &vis, vector<int> &pathVis, int node)
{
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto i: v[node])
    {
        if(!vis[i])
        {
            bool a = dfs(v, vis, pathVis, i);
            if(!a) return a;

        }
        else if(pathVis[i]) return false;
    }
    pathVis[node] = 0;
    return true;
}
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<vector<int>> v(n);
        for(int i = 0; i < p.size(); i++)
        {
            v[p[i][1]].push_back(p[i][0]);
        }
        vector<int> vis(n, 0), pathVis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                if(!dfs(v, vis, pathVis, i)) return false;
            }
        }
        return true;
    }
};
