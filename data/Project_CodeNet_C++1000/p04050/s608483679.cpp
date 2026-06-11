#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    if (m == 1) {
        if (n == 1) {
            cout << "1\n1\n1";
            return 0;
        } else {
            cout << a[0] << '\n';
            cout << 2 << '\n' << a[0] - 1 << ' ' << 1 << '\n';
            return 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) if (a[i] % 2 == 1) ++cnt;
    if (cnt > 2) {
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 1; i < m; ++i) {
        if (a[i] % 2 == 1) {
            if (a[0] % 2 == 0) swap(a[0], a[i]);
            else swap(a[i], a.back());
        }
    }
    for (int i = 0; i < m; ++i) cout << a[i] << ' ';
    cout << '\n';
    cout << (a[0] == 1 ? m - 1 : m) << '\n';
    if (a[0] > 1) cout << a[0] - 1 << ' ';
    for (int i = 1; i + 1 < m; ++i) {
        cout << a[i] << ' ';
    }
    if (m > 1) cout << a[m - 1] + 1 << '\n';
}