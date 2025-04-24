class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long s = 0, a = 0, b = 0;
        for(auto i: diff)
        {
            s += i;
            a = min(a, s);
            b = max(b, s);
        }
        return max(0L, (upper - b) + (a - lower) + 1);
    }
};
