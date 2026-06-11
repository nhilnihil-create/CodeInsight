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
    const ll inf = LONG_LONG_MAX / 2 - 1;
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll mx = -inf, mn = inf;
    map<ll, ll> cnt;
    rep(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        cnt[a[i]]++;
    }
    bool ans = true;
    if (mx % 2 == 0) {
        if (mn != (mx / 2)) ans = false;
        if (cnt[mn] != 1) ans = false;
    }
    else {
        if (mn != ((mx + 1) / 2)) ans = false;
        if (cnt[mn] != 2) ans = false;
    }
    reps(i, mn + 1, mx + 1) {
        if (cnt[i] < 2) ans = false;
    }
    cout << (ans ? "Possible" : "Impossible") << endl;
    return 0;
}
