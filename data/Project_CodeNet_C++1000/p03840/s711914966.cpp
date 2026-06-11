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
    ll ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;
    ll ans = 0;
    if ((ai >= 1) && (aj >= 1) && (al >= 1)) {
        ans = 3;
        ans += (ai - 1) / 2 * 2;
        ans += (aj - 1) / 2 * 2;
        ans += (al - 1) / 2 * 2;
        ans += ao;
    }
    ll tmp = 0;
    tmp += ai / 2 * 2;
    tmp += aj / 2 * 2;
    tmp += al / 2 * 2;
    tmp += ao;
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}
