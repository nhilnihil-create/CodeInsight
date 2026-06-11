#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((ll)((a) + (b) - 1)/(ll)(b))

int pow2[13];

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    int ans[2];
    ans[0] = ans[1] = 0;
    
    rep(turn, 2){
        int now = 0;
        rep(i,n){
            now += a[i];
            if(i % 2 == turn){
                if(now > 0) continue;
                ans[turn] += 1 - now;
                now = 1;
            }else{
                if(now < 0) continue;
                ans[turn] += 1 + now;
                now = -1;
            }
        }
    }
    
    cout << min(ans[0], ans[1]) << endl;
}