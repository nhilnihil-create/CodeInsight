#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
const int INF = 1e9 + 100;

int a[1500][1500];

int main() {
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < n + m; ++i) {
        for (int j = 0; j < n + m; ++j) {
            a[i][j] = ((i / d) % 2) + (((j / d) % 2) * 2);
        }
    }
    string s = "RBGY";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = i + j;
            int y = n - i + j;
            cout << s[a[x][y]];
        }
        cout << endl;
    }

    return 0;
}
