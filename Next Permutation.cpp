class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int ind = -1, n = v.size();
        for (int i = n - 2; i >= 0; --i) {
            if (v[i] < v[i + 1]) {
                ind = i;

                break;
            }
        }

        if (ind == -1)
            reverse(v.begin(), v.end());
        else {
            for (int i = n - 1; i > ind; i--) {
                if (v[i] > v[ind]) {
                    swap(v[i], v[ind]);
                    break;
                }
            }
            reverse(v.begin() + ind + 1, v.end());
        }
    }
};
