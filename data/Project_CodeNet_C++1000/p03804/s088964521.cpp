#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n], t[m];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n - m; i++) {
        for (int j = 0; j < n - m; j++) {
            bool foun = true;
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < m; c++) {
                    if (t[r][c] != s[i + r][j + c]) {
                        foun = false;
                        break;
                    }
                }
            }
            if (foun) {
                cout << "Yes" << '\n', exit(0);
            }
        }
    }
    if (n == m && n == 1) {
        cout << "Yes" << '\n';
    } else cout << "No" << '\n';
    return 0;
}