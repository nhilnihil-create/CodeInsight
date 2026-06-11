#include <bits/stdc++.h>
using namespace std;
int n, a;
int x[100];
long long ans = 0;
long long m[50][51][2510];
long long solve(int i, int p, int q) {
    if (p == 0 && q == 0) {
        return 1;
    }
    if (q < 0) {
        return 0;
    }
    if (i == n) {
        return 0;
    }
    if (n-i < p) return 0;
    if (m[i][p][q] != -1) return m[i][p][q];
    return m[i][p][q] = solve(i+1, p-1, q-x[i]) + solve(i+1, p, q);
}
int main () {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 51; j++) {
            for (int k = 0; k < 2510; k++) {
                m[i][j][k] = -1;
            }
        }
    }
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x+n);
    for (int i = 1; i <= n; i++) {
        ans += solve(0, i, i*a);
    }
    cout << ans << endl;
}