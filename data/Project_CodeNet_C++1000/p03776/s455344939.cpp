//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

struct combination {
    vector<ll> frac;
    combination(int n):frac(n+1) {
        frac[0] = 1;
        rep(i, n) {
            frac[i+1] = (n-i) * frac[i];
            frac[i+1] /= i+1;
        }
    }
} ;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i, n) {
        cin >> v[i];
    }

    sort(rall(v));
    ld ave = 0;
    vi x;
    for(int i = a; i <= b; ++i) {
        ll sum = 0;
        rep(j, i) {
            sum += v[j];
        }
        ld now = (ld)sum/i;
        if(now > ave+1e-10) {
            x.clear();
            x.push_back(i);
            ave = now;
        } else if(abs(now-ave) < 1e-10) {
            x.push_back(i);
        }
    }

    cout << fixed << setprecision(10);
    cout << ave << endl;

    ll ans = 0;
    reverse(all(v));
    rep(i, x.size()) {
        ll now = x[i];
        ll num = v[n-now];
        vector<ll>::iterator itr, itu;
        itr = lower_bound(all(v), num);
        itu = upper_bound(all(v), num);
        ll hh = now - (v.end()-itu);
        ans += combination(itu-itr).frac[hh];
    }

    cout << ans << endl;
}