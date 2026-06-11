#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll mv = LONG_LONG_MIN, mi = -1;
    rep(i, n - 1) {
        ll val = a[i] + a[i + 1];
        if (mv < val) {
            mv = val;
            mi = i;
        }
    }
    if (mv < l) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    rep(i, mi) {
        cout << (i + 1) << endl;
    }
    rreps(i, mi, n - 1) {
        cout << (i + 1) << endl;
    }
    return 0;
}
