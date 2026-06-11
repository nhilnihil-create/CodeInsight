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
    ll n;
    cin >> n;
    map<ll, ll> m;
    rep(i, n) {
        ll a;
        cin >> a;
        m[a] = i;
    }
    set<ll> s;
    s.insert(-1);
    s.insert(n);
    ll ans = 0;
    reps(i, 1, n + 1) {
        auto it = s.lower_bound(m[i]);
        ll r = *it - m[i];
        it--;
        ll l = m[i] - *it;
        ans += l * r * i;
        s.insert(m[i]);
    }
    cout << ans << endl;
    return 0;
}
