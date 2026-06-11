/*input
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
const int maxm = 4e6 + 5;
const int mod = 1e9 + 7;

long long numer[maxm];
long long denom[maxm];

int f[maxn][maxn];

void add(int &a, int b) {
    a = (a + b) % mod;
}

int C(int n, int k) {
    if(k > n) return 0;
    return numer[n] * denom[k] % mod * denom[n - k] % mod;
}

int main() {
    numer[0] = denom[0] = denom[1] = 1;
    for(int i = 1; i < maxm; ++ i) numer[i] = numer[i - 1] * i % mod;
    for(int i = 2; i < maxm; ++ i) denom[i] = - (mod / i) * denom[mod % i] % mod + mod;
    for(int i = 2; i < maxm; ++ i) denom[i] = denom[i] * denom[i - 1] % mod;

    int n, k; cin >> n >> k;
    if(k == 1) return puts("1"), 0;

    f[0][0] = 1;
    for(int i = 0; i <= n; ++ i) for(int j = 0; j <= i; ++ j) if(f[i][j]) {
        // add another white ball to the end
        add(f[i + 1][j], f[i][j]);

        // take away 1 white ball
        if(j < i) {
            // choosing a color to fill in
            long long cur = 1ll * f[i][j] * (n - j) % mod;
            cur = 1ll * cur * C(n * k - i - j - 1 - j * (k - 2), k - 2) % mod;
            add(f[i][j + 1], cur);
        }
    }
    cout << f[n][n] << endl;
}
