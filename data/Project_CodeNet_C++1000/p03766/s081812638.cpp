#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 6100000;
const int K = 19;
const int mod = 1e9 + 7;
int dp[N], s[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    dp[1] = n;
    s[1] = n;
    for (int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] +  (n - 1) * (n - 1)) % mod;;
        if (i >= 4){
            dp[i] = (dp[i] + s[i - 3]) % mod;
            dp[i] = (dp[i] + n - i + 2) % mod;
        } else dp[i] = (dp[i] + n - 1) % mod;
        s[i] = (s[i - 1] + dp[i]) % mod;
     //   cout << dp[i] << endl;
    }
    cout << dp[n];
}
