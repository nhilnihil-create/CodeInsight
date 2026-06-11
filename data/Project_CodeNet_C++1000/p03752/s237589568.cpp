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

ll a[20];

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    ll ans = LINF;
    for(ll bits = 0; bits < (1ll<<n); bits++){
        if (bits%2 == 0 || __builtin_popcount(bits) != k) continue;
        ll now = a[0], tmp = 0;
        for(int i = 1; i < n; i++){
            if (bits&(1<<i)){
                if (now >= a[i]) {
                    now += 1;
                    tmp += now - a[i];
                }
                else now = a[i];
            }
            else now = max(now, a[i]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
