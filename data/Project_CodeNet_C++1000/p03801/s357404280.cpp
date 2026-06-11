#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll ans[100010];

int main(){
    int n;
    cin >> n;
    vector<P> vp(n+1);

    rep(i, n) {
        ll a;
        cin >> a;
        vp.push_back({a, i});
    }
    sort(vp.rbegin(), vp.rend()); // aが大きいもの、同立ならiが大きいものから取っていく

    ll idx = LINF;
    rep(i, n){
        idx = min(idx, vp[i].second);
        ans[idx] += (i + 1) * (vp[i].first - vp[i+1].first);
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
