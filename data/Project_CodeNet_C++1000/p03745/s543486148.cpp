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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll dir = 0, ans = 1, bv = a[0];
    rep(i, n) {
        if (bv == a[i]) continue;
        if (dir == 0) {
            if (bv < a[i]) dir = 1;
            else dir = -1;
        }
        else if (dir == 1) {
            if (bv >= a[i]) {
                dir = 0;
                ans++;
            }
        }
        else {
            if (bv <= a[i]) {
                dir = 0;
                ans++;
            }
        }
        bv = a[i];
    }
    cout << ans << endl;
    return 0;
}
