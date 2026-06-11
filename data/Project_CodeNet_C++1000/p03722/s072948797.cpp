#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 10000000000000LL;

int main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m], c[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    ll d[n];
    for (int i = 0; i < n; i++) d[i] = -inf;
    d[0] = 0;
    bool update = true;
    int cnt = 0;
    ll ds;
    bool flag = false;

    while (update && cnt < 2 * n) {
        cnt++;
        update = false;
        for (int i = 0; i < m; i++) {
            if (d[b[i]] < d[a[i]] + c[i]) {
                d[b[i]] = d[a[i]] + c[i];
                update = true;
            }
        }
        if (cnt == n - 1) ds = d[n - 1];
        if (cnt == 2 * n && ds < d[n - 1]) flag = true;
    }

    if (flag) cout << "inf" << endl;
    else cout << d[n - 1] << endl;
    return 0;
}