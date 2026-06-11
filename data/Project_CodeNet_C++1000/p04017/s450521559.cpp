#include<bits/stdc++.h>
using namespace std;
#define N 100000 + 5
#define rep(i, l, r) for(int i = l; i <= r; ++i)
int n, l, q, a, b, tot, siz, x[N], nxt[N], last[N], cntb[N], block[N];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int main(){
    n = read(), siz = sqrt(n), tot = ceil(1.0 * n / siz);
    rep(i, 1, n) x[i] = read();
    l = read(); 
    rep(i, 1, n){
        int pos = upper_bound(x + 1, x + n + 1, x[i] + l) - x;
        if(x[pos] < x[i] + l) last[i] = n + 1;
        else last[i] = pos - 1;
    }
    block[n + 1] = tot + 1;
    rep(i, 1, n) block[i] = i / siz + 1;
    rep(i, 1, n){
        int pos = i, cnt = 0;
        while(block[pos] == block[i]) pos = last[pos], ++cnt;
        cntb[i] = cnt, nxt[i] = pos;
    }
    q = read();
    while(q--){
        a = read(), b = read(); if(a > b) swap(a, b);
        int pos = a, ans = 0;
        while(block[pos] < block[b]) ans += cntb[pos], pos = nxt[pos];
        while(pos < b) pos = last[pos], ++ans;
        printf("%d\n", ans);
    }
    return 0;
}