class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int m = 0, n = v.size();
        sort(v.begin(), v.end());
        vector<int> dp(n+1, 0), prev(n+1, -1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(v[i]%v[j] == 0 and dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
                
            }
            if(dp[i] > dp[m]) m = i;
        }
        vector<int> ans;
        for(int i = m; i >= 0; i = prev[i]){
            ans.push_back(v[i]);
        }
        return ans;

    }
};
