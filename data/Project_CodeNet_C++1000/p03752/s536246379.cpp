#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
//const int MOD = 1e9 + 7;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    int ans = 1e12;
    
    bitset<20> b;
    for(int bi = 0; bi < (1 << n); ++bi) {
        b = bi;
        if(b.count() < k) continue;
        auto t = a;
        int max_h = 0;
        
        for(int i = 0; i < n; ++i) {
            if(b[i]) {
                t[i] = max(t[i], max_h + 1);
            }
            max_h = max(max_h, t[i]);
        }
        
        int cost = 0;
        rep(i,n) cost += t[i] - a[i];
        ans = min(ans, cost);
    }
    
    cout << ans << endl;
}