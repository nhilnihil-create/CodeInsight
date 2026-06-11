#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[n], c[m], d[m];
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    rep(i, m) {
        cin >> c[i] >> d[i];
    }
    rep(i, n) {
        int min_d = 1e9;
        int p;
        rep(j, m) {
            if (abs(a[i] - c[j]) + abs(b[i] - d[j]) < min_d) {
                min_d = abs(a[i] - c[j]) + abs(b[i] - d[j]);
                p = j+1;
            }
        }
        cout << p << endl;
    }
}