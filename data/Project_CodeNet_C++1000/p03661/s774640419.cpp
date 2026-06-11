#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 200005
#define eps 1e-12
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
        out(x / 10);
    }
    putchar('0' + x % 10);
}
int N;
int64 s[MAXN];
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(s[i]);
    for(int i = 1 ; i <= N ; ++i) s[i] += s[i - 1];
    int64 ans = abs(s[N] - 2 * s[1]);
    for(int i = 1 ; i < N ; ++i) {
        ans = min(ans,abs(s[N] - 2 * s[i]));
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
    Solve();
}
