#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2000 + 7;

long long f[maxn][maxn];
long long step[maxn * maxn], inv[maxn * maxn];

long long C(int n, int m) {
    return step[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        printf("1\n");
        return 0;
    }

    long long ans = 1;
    for (int i = 1; i <= n; i++) ans = ans * i % mod;

    step[0] = 1;
    for (int i = 1; i <= n * k; i++) step[i] = step[i - 1] * i % mod;

    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n * k; i++) 
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    for (int i = 2; i <= n * k; i++) 
        inv[i] = inv[i  - 1] * inv[i] % mod;
    
    f[0][0] = 1;

    for (int i = 0; i <= n; i++) 
    for (int j = i; j <= n; j++) {
        long long &rt = f[i][j];

        if (j > i) 
            rt = C((k - 1) * j + i - 1, k - 2) * f[i][j - 1] % mod;
        if (i > 0) {
            rt = (rt + f[i - 1][j]) % mod;
        }
    }

    cout << ans * f[n][n] % mod << endl;
    return 0;
}