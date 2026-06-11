#include <bits/stdc++.h>
using namespace std;
const int N=2020;
const int mod=1e9+7;
int inv[N*N],fac[N*N];
int f[N][N];
int n, k;
inline int C(int n, int m) {return 1ll * fac[m] * inv[n] % mod * inv[m - n] % mod;}
inline int power(int a, int b) 
{
    a %= mod; int ans = 1;
    while(b) {
        if(b & 1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a % mod; b >>= 1;
    }
    return ans%mod;
}
int main() {
    scanf("%d%d", &n, &k);
    if(k==1) {puts("1"); return 0;}
    fac[0] = 1;
    for(int i = 1; i < N * N; ++i) 
        fac[i] = 1ll * fac[i - 1] * i % mod;
    for(int i = 0; i < N * N; ++i) 
        inv[i] = power(fac[i], mod - 2);
	f[0][0]=1;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= i; ++j) {
            f[i][j] = f[i - 1][j];
			if(!j) continue;
            (f[i][j] += 1ll * (n - j + 1) * f[i][j - 1] % mod * C(k - 2, n * k - i - (j - 1) * (k - 1) - 1) % mod) %= mod;
            f[i][j]=(f[i][j]+mod)%mod;
        }
    printf("%d\n",f[n][n]);
    return 0;
}