class Solution {
public:
    long long distributeCandies(int n, int limits) {
        long long ans = 0;
        for(int i = 0; i <= min(limits, n); i++)
        {
            if(n - i > 2*limits) continue;
            ans += min(limits, n - i) - max(n - i - limits, 0) + 1;
        }
        return ans;
    }
};
