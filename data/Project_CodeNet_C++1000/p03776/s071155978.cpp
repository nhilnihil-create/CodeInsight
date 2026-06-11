#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll C[51][51];

void comb(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    comb(n);
    ll v[n];
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n);
    reverse(v, v + n);
    ll k = 0;
    for (int i = 0; i < a; i++) k += v[i];
    double ans = (double)k / a;
    ll cnt = 0;
    if (v[0] > v[a - 1]) {
        int p = 0, q = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == v[a - 1]) {
                p++;
                if (i < a) q++;
            }
        }
        cnt = C[p][q];
    } else {
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == v[0]) p++;
        }
        for (int i = a; i <= min(p, b); i++) {
            cnt += C[p][i];
        }
    }
    printf("%0.10f\n", ans);
    cout << cnt << endl;
    return 0;
}