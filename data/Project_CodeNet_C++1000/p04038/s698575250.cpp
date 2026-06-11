#include<bits/stdc++.h>
const int N = 4e6 + 5;
const int mod = 1e9 + 7;
using namespace std;

int n, k, f[N], dp[2005][2005], sum[2005][2005], inv[N], ans;

int C(int k, int n){
    if (k < 0 || k > n) return 0;
    return 1LL * f[n] * inv[k] % mod * inv[n-k] % mod;
}

int po(int n, int k){
    int ans = 1;
    while (k){
        if (k&1) ans = 1LL * ans * n % mod;
        n = 1LL * n * n % mod;
        k >>= 1;
    }
    return ans;
}

void add(int& a, int b){
    a += b; if (a >= mod) a -= mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = 1LL * f[i-1] * i % mod;
    inv[N-1] = po(f[N-1], mod-2);
    for (int i = N-2; i >= 0; i--) inv[i] = 1LL * inv[i+1] * (i+1) % mod;
    cin >> n >> k;
    if (k == 1) return cout << 1, 0;
    dp[1][1] = 1; sum[1][1] = sum[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 1; j--){
            add(dp[i][j], 1LL * sum[i-1][j-1] * C(k-2, i*k-j-1) % mod * i % mod);
        }
        for (int j = n; j >= 0; j--) sum[i][j] = sum[i][j+1], add(sum[i][j], dp[i][j]);
    }
    for (int i = 1; i <= n; i++) add(ans, dp[n][i]);
    cout << ans;
}