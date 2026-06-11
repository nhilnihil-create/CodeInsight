#include <bits/stdc++.h>
using namespace std;
 
#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((ll)((a) + (b) - 1)/(ll)(b))

signed main(){
    int n, a;
    int tpcost;
    cin >> n >> a >> tpcost;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    
    int ans = 0;
    rep(i,n-1){
        int walkcost = (x[i+1]-x[i]) * a;
        ans += min(walkcost, tpcost);
    }
    
    cout << ans << endl;
}