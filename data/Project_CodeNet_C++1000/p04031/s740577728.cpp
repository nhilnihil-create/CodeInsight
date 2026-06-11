#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
const int MOD = 1e9 + 7;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = INT_MAX;
    for(int y = -100; y <= 100; y++){
        int cost = 0;
        for(int x : a){
            cost += (x-y)*(x-y);
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}