class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        vector<int> c(n, 1), d(n, 1);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty())
            {
                if(v[i] > v[st.top()]) c[i] += c[st.top()];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; ++i)
        {
            while(!st.empty())
            {
                if(v[i] > v[st.top()]) d[i] += d[st.top()];
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i < n; ++i)
        c[i] = max(c[i], d[i]);
        int ans = accumulate(c.begin(), c.end(), 0);
        return ans;
    }
};
