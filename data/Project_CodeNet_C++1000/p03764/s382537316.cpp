#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int n, m;
int x[100000], y[100000];
int mod = 1e9 + 7;

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    int x_sum = 0, y_sum = 0;
    for (int i = 1; i < n; i++) {
        x_sum = (x_sum + (x[i] - x[i - 1]) * i * (n - i) % mod) % mod;
    }
    for (int i = 1; i < m; i++) {
        y_sum = (y_sum + (y[i] - y[i - 1]) * i * (m - i) % mod) % mod;
    }
    cout << x_sum * y_sum % mod << endl;
    return 0;
}
