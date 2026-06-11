#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

ll s, c;
int main() {
    cin >> s >> c;
    ll l = 0, r = s + c;
    while (l < r) {
        ll m = (r - l + 1) / 2 + l;
        bool ok = true;
        // scc
        if (m * 2 > c) {
            ok = false;
        } else {
            if (m > s) {
                ll d = (c - m * 2) / 2;
                if (s + d < m)
                    ok = false;
            }
        }
        if (ok)
            l = m;
        else
            r = m - 1;
    }
    cout << l << endl;
    return 0;
}
