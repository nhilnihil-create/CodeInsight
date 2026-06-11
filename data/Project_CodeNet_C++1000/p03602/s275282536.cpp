#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    bool isNecessary[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            isNecessary[i][j] = true;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    cout << -1 << endl;
                    return 0;
                }
                if (a[i][j] == a[i][k] + a[k][j] && a[i][k] > 0 && a[k][j] > 0) {
                    isNecessary[i][j] = false;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isNecessary[i][j]) ans += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}