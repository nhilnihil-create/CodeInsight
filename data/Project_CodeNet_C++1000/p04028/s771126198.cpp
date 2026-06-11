#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 30000;
const int K = 100000;
const int mod = 1e9 + 7;
int dp[N], f[N], invf[N], n;
vector <int> a;
int binpow(int x, int y){
    int res = 1;
    while(y){
        if (y % 2) res = res * x % mod;
        y /= 2;
        x = x * x % mod;
    }
    return res;
}
int c(int n){
    return f[n + n] * invf[n + 1] % mod * invf[n] % mod;
}
vector <int> bp(vector <int> b, int x){
    if (x == 1) return b;
    vector <int> res(n);
    if (x % 2 == 1){
        vector <int> c = bp(b, x - 1);
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                res[i] = (res[i] + c[j] * b[i - j]) % mod;
            }
        }
        return res;
    } else{
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                res[i] = (res[i] + b[j] * b[i - j]) % mod;
            }
        }
        return bp(res, x / 2);
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    string s;
    cin >> s;
    int m = s.length();
    f[0] = invf[0] = 1;
    for (int i = 1; i <= 2 * n; i++) f[i] = f[i - 1] * i % mod;
    for (int i = 1; i <= 2 * n; i++) invf[i] = binpow(f[i], mod - 2);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        for (int j = 1; 2 * j <= i; j++){
            dp[i] = (dp[i] + dp[i - 2 * j] * binpow(2, j) % mod * c(j - 1)) % mod;
        }
    }
 //   for (int i = 0; i <= n + m; i++) cout << dp[i] << " ";
 //   cout << endl;
    for (int i = 0; i < n; i++) a.pb(binpow(2, i) * c(i) % mod);
    a = bp(a, m);
  //  for (int i = 0; i < n; i++) cout << a[i] << " ";
    int ans = 0;
    for (int i = 0; i <= n - m; i++){
        if ((n - i - m) % 2) continue;
        ans = (ans + dp[i] * a[(n - i - m) / 2]) % mod;
    }
    cout << ans;
}
