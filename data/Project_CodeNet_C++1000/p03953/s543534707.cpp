#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
const int N = 100000 + 5;
bool book[N];
int n, m, k, tmp, cnt, a[N], d[N], p[N], dp[N], nxt[N], ans[N];
vector <int> G[N];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
signed main(){
    n = read();
    rep(i, 1, n) d[i] = read(), p[i] = i, dp[i] = d[i] - d[i - 1];
    m = read(), k = read();
    rep(i, 1, m) a[i] = read(), swap(p[a[i]], p[a[i] + 1]);
    rep(i, 1, n) nxt[i] = p[i]; 
    rep(i, 1, n) if(!book[i]){
        int x = i; G[++cnt].push_back(i), book[i] = true;
        while(nxt[x] != i) x = nxt[x], book[x] = true, G[cnt].push_back(x);
    }
    rep(i, 1, cnt){
        int S = G[i].size(), tr = k % S;
        rep(j, 0, S - 1) ans[G[i][j]] = dp[G[i][(j + tr) % S]];
    }
    rep(i, 1, n) tmp += ans[i], printf("%lld.0\n", tmp);
    return 0;
}