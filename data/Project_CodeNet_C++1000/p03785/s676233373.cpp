#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    int pnum = 0;
    int st = t[0];
    int ti = t[0];
    int ans = 1;
    rep(i, n) {
        ti = t[i];
        pnum++;
        if(pnum > c || st + k < ti) {
            ans++;
            pnum = 1;
            st = t[i];
        }
    }
    cout << ans << endl;
    return 0;
}
