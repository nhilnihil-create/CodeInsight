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
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    string s, t;
    ll q;
    cin >> s >> t >> q;
    ll ns = len(s), nt = len(t);
    vector<ll> sdp(ns + 1, 0), tdp(nt + 1, 0);
    rep(i, ns) {
        sdp[i + 1] = sdp[i] + ((s[i] == 'B') ? 2 : 1);
    }
    rep(i, nt) {
        tdp[i + 1] = tdp[i] + ((t[i] == 'B') ? 2 : 1);
    }
    rep(i, q) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        ll sc = sdp[b + 1] - sdp[a];
        ll tc = tdp[d + 1] - tdp[c];
        if (abs(sc - tc) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
