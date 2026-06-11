#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[n], c[m], d[m];
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];

    rep(i, n) {
        int minv = 1e9, idx = 0;
        rep(j, m) {
            int dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (dist < minv) minv = dist, idx = j + 1;
        }
        cout << idx << endl;
    }

    return 0;
}
