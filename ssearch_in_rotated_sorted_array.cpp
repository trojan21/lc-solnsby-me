class Solution {
public:
    int search(vector<int>& v, int t) {
        int n = v.size(), l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(t == v[mid]) return mid;
            if(t > v[mid]){
                if(t <= v[r]) l = mid + 1;
                else if(v[mid] >= v[l]) l = mid + 1;
                else r = mid - 1;
            }
            else{
                if(t >= v[l]) r = mid - 1;//here once i wrote the condition t <= v[r] this is however wrong becoz then some of the cases of the 3rd condition will collide here
                else if(v[mid] >= v[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
