#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    ll m = 1, pt, pa;
    for (ll i = 0, t, a; i < n; i++) {
        cin >> t >> a;
        if (i == 0) {
            pt = t, pa = a;
            continue;
        }
        m = max((pt * m + t - 1) / t, (pa * m + a - 1) / a);
        pt = t, pa = a;
    }
    cout << pt * m + pa * m << endl;
}