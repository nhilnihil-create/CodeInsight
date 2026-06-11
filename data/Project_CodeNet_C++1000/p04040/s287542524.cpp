#include<bits/stdc++.h>
using namespace std;
#define N 200000 + 5
#define Mod 1000000007
#define rep(i, l, r) for(int i = l; i <= r; ++i)
int n, m, a, b, ans, f[N], inv[N];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
int Dec(int a, int b){
    return (a -= b) < 0 ? a + Mod : a;
}
int Mul(int a, int b){
    return 1ll * a * b % Mod;
}
int Qpow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = Mul(ans, a);
        a = Mul(a, a), b >>= 1;
    }
    return ans;
}
int C(int n, int m){
    return Mul(f[n], Mul(inv[m], inv[n - m]));
}
int main(){
    n = read() - 1, m = read() - 1, a = read(), b = read();
    f[0] = inv[0] = 1;
    rep(i, 1, N - 5) f[i] = Mul(f[i - 1], i), inv[i] = Qpow(f[i], Mod - 2);
    rep(i, b, m) ans = Inc(ans, Mul(C(n - a + i, n - a), C(a + m - i - 1, a - 1)));
    printf("%d", ans);
    return 0;
}