#include <bits/stdc++.h>
#define mset(arr, val) memset(arr, val, sizeof(arr))
#define ll long long
#define endl "\n"
using namespace std;
// const double PI = acos(-1.0);
// const double E = exp(1.0);
// const double EPS = 1e-9;
const int MOD = (int)1e9 + 7;
const int N = (int)1e5;

int main()
{
#ifdef MY_PREPROCESSOR
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int64_t a, b, x;
    cin >> a >> b >> x;
    int64_t ans = (b / x) - (a / x);
    if (a % x == 0)
        ans++;
    cout<< ans;
    
    return 0;
}