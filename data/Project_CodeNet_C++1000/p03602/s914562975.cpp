#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

extern inline char gc() {
    static char RR[23456], *S = RR + 23333, *T = RR + 23333;
    if(S == T) fread(RR, 1, 23333, stdin), S = RR;
    return *S ++;
}
inline int read() {
    int p = 0, w = 1; char c = gc();
    while(c > '9' || c < '0') { if(c == '-') w = -1; c = gc(); }
    while(c >= '0' && c <= '9') p = p * 10 + c - '0', c = gc();
    return p * w;
}

#define ri register int
#define sid 305

int n;
int v[sid][sid], mp[sid][sid];

int main() {
    n = read();
    for(ri i = 1; i <= n; i ++)
    for(ri j = 1; j <= n; j ++)
    v[i][j] = mp[i][j] = read();

    bool flag = 0;

    for(ri i = 1; i <= n; i ++)
    for(ri j = 1; j <= n; j ++)
    for(ri k = 1; k <= n; k ++)
    if(i != k && j != k && i != j) {
        if(mp[i][j] > mp[i][k] + mp[k][j]) flag = 1;
        if(mp[i][j] == mp[i][k] + mp[k][j])
        v[i][j] = v[j][i] = 0;
    }

    long long ans = 0;
    for(ri i = 1; i <= n; i ++)
    for(ri j = 1; j <= n; j ++)
    ans += v[i][j];
    
    if(flag) printf("-1\n");
    else printf("%lld\n", ans / 2);
    return 0;
}