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

ll a[100010], b[100010];

vector<ll> v;

int main(){
    ll n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i] >> b[i];
    
    int r = 0;
    rep(i, 35) if (k&1ll<<i) r = i;


    v.push_back(k);
    rep(i, r){
        ll tmp = k;
        if (1ll<<(r-i) & k) {
            tmp -= 1ll<<(r-i);
            rep(j, r-i) tmp |= 1ll<<j;
        }
        v.push_back(tmp);
    }

    ll ans = 0;
    for(auto e : v) {
        // cout << e << endl;
        ll res = 0;
        rep(i, n) {
            if ((e|a[i]) == e) res += b[i];
            // cout << e << " " << a[i] << " " << (e|a[i]) << endl;
        }
        ans = max(ans, res);
    }

    cout << ans << endl;
    return 0;

}
