#include <bits/stdc++.h>
using namespace std;
#define maxn 10000000
#define mod 1000000007 
int n, ans, f[maxn], sum[maxn];

int read() {
    int x = 0, k = 1;
    char c; c = getchar();
    while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar(); 
    return x * k;
}

void Upd(int &x, int y) { x = (x + y) % mod; }
int Up(int x, int y) { x += y; if(x >= mod) x -= mod; return x; }
int Down(int x, int y) { x -= y; if(x < 0) x += mod; return x; }
int mul(int x, int y) { return 1ll * x * y % mod; }

int main() {
    n = read(); f[0] = sum[0] = 1; 
    for(int i = 1; i <= n; i ++) {
        Upd(f[i], i >= 3 ? sum[i - 3] : 0);
        Upd(f[i], f[i - 1]); Upd(sum[i], Up(f[i], sum[i - 1]));
    }
    for(int i = 1; i < n; i ++) Upd(ans, mul(Up(mul(n - 1, n - 1), i), f[i - 1]));
    Upd(ans, 1ll * f[n - 1] * (n - 1) % mod); Upd(ans, f[n]);
    printf("%d\n", ans);
    return 0;
}