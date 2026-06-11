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
    vector<ll> cnt(n, 1);
    vector<bool> red(n, false);
    red[0] = true;
    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        if (!red[x]) {
            cnt[x]--;
            cnt[y]++;
        }
        else {
            if (cnt[x] == 1) {
                red[x] = false;
            }
            cnt[x]--;
            cnt[y]++;
            red[y] = true;
        }
    }
    ll ans = 0;
    rep(i, n) ans += (red[i] ? 1 : 0);
    cout << ans << endl;
    return 0;
}
