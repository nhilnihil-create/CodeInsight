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

int inf = 4e18, mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n,sum; cin >> n;
    string s; cin >> s;
    int l = s.size();
    vi p2(n+1);
    vector<vi> dp(n+1, vi(n+1,0));
    p2[0] = dp[0][0] = 1;
    for(int i=1;i <= n; i++){
        dp[i][0] = 1;
        p2[i] = p2[i-1] * 2 % mod;
        for(int j = 1;j<=n;j++){
            dp[i][j] = dp[i-1][j] + (i - 1 - (j - 1) * 2 > 0 ? dp[i-1][j-1] : 0);
            dp[i][j] %= mod;
        }
    }
    sum = p2[(n - l) / 2] * ((n - l) % 2 ? 0 :dp[n][(n - l) / 2]) % mod;
    sum += p2[(n - l - 1) / 2] * ((n - l - 1) % 2 ? 0 :dp[n - 1][(n - l - 1) / 2]) % mod;
    for(int i = 1, er;i < n; i++){
        int tmp = 0;
        for(int j = 0; j < i; j++){
            tmp = (tmp + dp[i][j] * p2[j] % mod) % mod;
        }
        er = n - i - 1 - l;
        if(er % 2 == 0 && er >= 0)
            sum = (sum + tmp * dp[n - i - 1][er / 2] % mod * p2[er / 2] % mod) % mod;
    }
    cout << sum << endl;
    return 0;
}

