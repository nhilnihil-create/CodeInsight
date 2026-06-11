#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    long long ans = 0;
    for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++) {
            bool rem = false;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;
                if (a[i][k] + a[k][j] < a[i][j]) { cout << "-1\n"; return 0; }
                if (!rem && a[i][k] + a[k][j] == a[i][j]) { ans -= a[i][j]; rem = true; }
            }
        }
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) ans += a[i][j];
    cout << ans << endl;
}
