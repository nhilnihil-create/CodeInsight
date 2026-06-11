#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    map<ll, ll> vcnt, mcnt;
    rep(i, n) {
        vcnt[x[i]]++;
        mcnt[x[i] % m]++;
    }
    ll ans = mcnt[0] / 2;
    mcnt[0] = 0;
    reps(i, 1, m) {
        ll j = m - i;
        if (i == j) {
            ans += mcnt[i] / 2;
            mcnt[i] = 0;
        }
        else {
            ll tmp = min(mcnt[i], mcnt[j]);
            ans += tmp;
            mcnt[i] -= tmp;
            mcnt[j] -= tmp;
        }
    }
    for(auto &x : vcnt) {
        ll v = x.first % m;
        ll s = min(x.second / 2, mcnt[v] / 2);
        ans += s;
        mcnt[v] -= s * 2;
    }
    cout << ans << endl;
    return 0;
}
