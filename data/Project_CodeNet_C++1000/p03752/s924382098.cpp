#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
ll n;
vector<bool> tobit(ll inp) {
    vector<bool> v(n, 0);
    int i = 0;
    while(inp) {
        v[i] = inp % 2;
        inp /= 2;
        i++;
    }
    return v;
}
int main() {
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = LLONG_MAX;
    for(ll i = 0; i < (1LL << n); i++) {
        ll tmp = 0;
        auto v = tobit(i);
        auto cp = a;
        for(int j = 0; j < n; j++) {
            if(v[j]) {
                ll m = -1;
                for(int p = 0; p < j; p++) {
                    m = max(m, cp[p]);
                }

                if(m >= cp[j]) {
                    tmp += m + 1 - cp[j];
                    cp[j] = m + 1;
                }
            }
        }
        ll tm = -1;
        ll cnt = 0;
        for(int j = 0; j < n; j++) {
            if(tm < cp[j]) {
                cnt++;
            }
            tm = max(tm, cp[j]);
        }
        if(cnt >= k) {
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}
