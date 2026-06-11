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
    string s;
    cin >> s;
    ll sl = len(s);
    map<ll, ll> m;
    rep(i, sl) m[s[i]]++;
    ll ans = sl * (sl - 1) / 2 + 1;
    for(auto x : m) {
        ans -= x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
