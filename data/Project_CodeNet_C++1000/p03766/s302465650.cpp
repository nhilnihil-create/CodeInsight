#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int         int64_t
#define ii          pair<int,int>
#define dd          pair<double,double>
#define vi          vector<int>
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define checkBit(v, p)      (v&(1LL << p))
#define loop(i,a,b) for(int i = a;i < int(b);i++)
#define x           first
#define y           second
using namespace std;
int inf = 2e9, mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n,res = 0; cin >> n;
    if(n == 1) return cout << n << endl, 0;
    if(n == 2) return cout << n * n % mod<< endl, 0;
    vi dp(n);
    dp[0] = dp[1] = 1;
    res = (n-1 + (n-1) * (n-1) * 2) % mod;
    for(int i = 2, tmp = 1;i < n;i++){
        dp[i] = tmp % mod;
        res = (res + dp[i] * (n-1) % mod * (i == n-1 ? 1 : (n-1)) % mod) % mod;
        res = (res + (n-1) * dp[i-1] % mod) % mod;
        tmp = (tmp + dp[i] + dp[i-2] - dp[i-1] + mod) % mod;
    }
    cout << (res + 1) % mod << endl;
    return 0;
}
