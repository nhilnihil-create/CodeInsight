#include<bits/stdc++.h>
using namespace std;
#define N 2000 + 5
#define M 4000000 + 5
#define Mod 1000000007
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define dep(i, l, r) for(int i = r; i >= l; --i)
int n, k, f[M], inv[M], dp[N][N];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int Inc(int a, int b){ return (a += b) >= Mod ? a - Mod : a;}
int Mul(int a, int b){ return 1ll * a * b % Mod;}
int Qpow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = Mul(ans, a);
        a = Mul(a, a), b >>= 1;
    }
    return ans;
}
int C(int n, int m){
    if(m > n) return 0;
    return Mul(f[n], Mul(inv[m], inv[n - m]));
}
int main(){
    n = read(), k = read();
    if(k == 1){ puts("1"); return 0;}
    f[0] = inv[0] = 1;
    rep(i, 1, M - 5) f[i] = Mul(f[i - 1], i);
    inv[M - 5] = Qpow(f[M - 5], Mod - 2);
    dep(i, 1, M - 6) inv[i] = Mul(inv[i + 1], i + 1);
    dp[0][0] = 1;
    rep(i, 1, n) rep(j, 0, i){
        dp[i][j] = Inc(dp[i][j], dp[i - 1][j]);
        if(j >= 1) dp[i][j] = Inc(dp[i][j], Mul(dp[i][j - 1], C(n * k - i - (j - 1) * (k - 1) - 1, k - 2)));
    }
    printf("%d", Mul(dp[n][n], f[n]));
    return 0;
}