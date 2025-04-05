class Solution {
public:
void solve(vector<int> &v, int l, int h, vector<vector<int>> &ans){
    if(l == h)
    {
        ans.push_back(v);
        return;
    }
    for(int i = l; i <= h; i++)
    {
        swap(v[l], v[i]);
        solve(v, l + 1, h, ans);
        swap(v[l], v[i]);
    }
   // return;
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, nums.size()-1, ans);
        return ans;
    }
};
/* Big Question in the recursive call line 12 why we call l + 1 rather than i + 1,
its because we wanna fix the l and then permute the further  subarray right after the fixed index after each swap
if we would have done  i + 1 then as step size increases we would have jumped to the greater numbers leaving behind the intermediate no.s
*/
