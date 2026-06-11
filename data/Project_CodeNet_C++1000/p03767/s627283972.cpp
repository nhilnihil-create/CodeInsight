#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int m = 3 * n;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, n) {
        ans += a[2 * i + n];
    }
    cout << ans << endl;
    return 0;
}
