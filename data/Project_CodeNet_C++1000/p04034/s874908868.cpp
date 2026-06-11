#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    ll x[m], y[m];
    rep(i, m) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    bool ans[n] = {};
    ll num[n];
    rep(i, n) { num[i] = 1; }
    ans[0] = true;

    rep(i, m) {
        if (ans[x[i]]) {
            ans[y[i]] = true;
        }
        num[x[i]]--;
        num[y[i]]++;
        if (num[x[i]] == 0) {
            ans[x[i]] = false;
        }
    }

    ll count = 0;
    rep(i, n) {
        if (ans[i])
            count++;
    }
    cout << count << endl;
    return 0;
}

