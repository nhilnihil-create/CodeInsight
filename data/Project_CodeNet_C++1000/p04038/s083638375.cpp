#include <iostream>
#define mod 1000000007
#define maxn 2003
using namespace std;
int fac[maxn * maxn], inv[maxn * maxn], f[maxn][maxn];
int fpw(int x, int y){
    int ans = 1;
    for (int i = 1; i <= y; i <<= 1, x = 1LL * x * x % mod)
        if (y & i)
            ans = 1LL * ans * x % mod;
    return ans;
}
int C(int n, int m){
    return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main(){
    int n, k;
    cin >> n >> k;
    if (k == 1){
        cout << 1 << endl;
        return 0;
    }
    fac[0] = 1;
    for (int i = 1; i <= n * k; ++ i)
        fac[i] = 1LL * fac[i - 1] * i % mod;
    inv[n * k] = fpw(fac[n * k], mod - 2);
    for (int i = n * k - 1; i >= 0; -- i)
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = 0; j <= i; ++ j){
            f[i][j] = f[i - 1][j];
            if (j)
                f[i][j] = (f[i][j] + 1LL * f[i][j - 1] * C(n * k - (j - 1) * (k - 1) - i - 1, k - 2) % mod * (n - j + 1)) % mod;
        }
    cout << f[n][n] << endl;
    return 0;
}
