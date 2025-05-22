class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        for(auto i: q){
            diff[i[0]] += 1;
            diff[i[1]+1] -= 1;
        }
        for(int i = 1; i <= n; i++)
        diff[i] = diff[i] + diff[i-1];
        for(int i = 0; i < n; ++i){
            nums[i] -= diff[i];
        }
        for(auto i: nums) if(i > 0) return false;
        return true;
    }
};
/* 
i used difference array for this
so diff array is used when you have to add a certain value in a range over the queries
lets say you have to add 5 to values from 3->7(l,r)
so you make a diffarray diff(n+1,0)
diff[l] += val, diff[r+1] -= val
and then when you take prefix sum of this you get the desired sum
Hence first you make changes by going over all the queries and then you do prefix sum
*/
