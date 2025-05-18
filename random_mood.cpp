#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    int n;
    double p;
    cin >> n >> p;
    double ans = 1.0;
    while (n > 0)
    {
        if (n % 2 == 1)
            ans = ans * (1 - p) + (1 - ans) * p;
        p = p * (1 - p) + (1 - p) * p;
        n /= 2;
    }
    cout << ans << endl;
    return 0;
}


//this is not a leetcode problem instead its a CF problem
