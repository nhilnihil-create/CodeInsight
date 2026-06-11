#include<bits/stdc++.h>
using namespace std;
#define N 100000 + 5
#define M 20 + 5
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define dep(i, l, r) for(int i = r; i >= l; --i)
int n, q, l, a, b, ans, x[N], f[N][M];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int main(){
    n = read();
    rep(i, 1, n) x[i] = read();
    l = read(); 
    rep(i, 1, n){
        int pos = upper_bound(x + 1, x + n + 1, x[i] + l) - x;
        if(x[pos] < x[i] + l) f[i][0] = n + 1;
        else f[i][0] = pos - 1;
    }
    rep(j, 1, M - 5) rep(i, 1, n) if(f[i][j - 1]) f[i][j] = f[f[i][j - 1]][j - 1];
    q = read();
    while(q--){
        a = read(), b = read(), ans = 0; if(a > b) swap(a, b);
        dep(i, 0, M - 5) if(f[a][i] < b && f[a][i]) a = f[a][i], ans += (1 << i);
        if(a < b) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}