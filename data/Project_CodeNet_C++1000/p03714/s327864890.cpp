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

ll a[300010];
multiset<ll> f, b;
ll fs = 0, bs = 0;
ll fl[100010], bl[100010];

int main(){
    int n;
    cin >> n;
    rep(i, 3*n) cin >> a[i];

    rep(i, n) {
        f.insert(a[i]);
        fs += a[i];
        b.insert(a[3*n-i-1]);
        bs += a[3*n-i-1];
    }
    fl[0] = fs;
    rep(i, n){
        ll tmp = *f.begin();
        if (a[n+i] > tmp){
            f.erase(f.find(tmp));
            f.insert(a[n+i]);
            fs += (a[n+i] - tmp);
        }
        fl[i+1] = fs;
    }
    bl[n] = bs;
    rep(i, n){
        ll tmp = *b.rbegin();
        if (a[2*n-i-1] < tmp){
            b.erase(b.find(tmp));
            b.insert(a[2*n-i-1]);
            bs += (a[2*n-i-1] - tmp);
        }
        bl[n-i-1] = bs;
    }

    // rep(i, n+1) cout << fl[i] << " ";
    // cout << endl;
    // rep(i, n+1) cout << bl[i] << " ";
    // cout << endl;

    ll ans = -LINF;

    rep(i, n+1) ans = max(ans, fl[i]-bl[i]);

    cout << ans << endl;

    return 0;
}
