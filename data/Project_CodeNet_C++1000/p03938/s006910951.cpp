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
    vector<ll> idx(n);
    rep(i, n) {
        cin >> idx[i];
        idx[i]--;
    }
    vector<ll> adp(n + 1, 0), bdp(n + 1, 0);
    rep(i, n) {
        ll cidx = idx[i];
        adp[cidx] += i;
        bdp[cidx + 1] -= i;
    }
    rep(i, n) {
        adp[i] += ((i > 0) ? adp[i - 1] : 0);
        bdp[i] += ((i > 0) ? bdp[i - 1] : 0);
    }
    vector<ll> a(n), b(n);
    rep(i, n) {
        a[i] = i + 1 + adp[i];
        b[i] = n - i + bdp[i] + abs(bdp[n - 1]);
    }
    rep(i, n) printf("%lld%s", a[i], (i == (n - 1)) ? "\n" : " ");
    rep(i, n) printf("%lld%s", b[i], (i == (n - 1)) ? "\n" : " ");
    return 0;
}
