#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 100005
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
struct node {
    int to,next;
}E[MAXN * 2];
int head[MAXN],sumE,N;
int dep[MAXN],fa[MAXN],siz[MAXN];
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u) {
    dep[u] = dep[fa[u]] + 1;
    siz[u] = 1;
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        if(v != fa[u]) {
            fa[v] = u;

            dfs(v);
            siz[u] += siz[v];
        }
    }
}
void Solve() {
    read(N);
    int u,v;
    for(int i = 1 ; i < N ; ++i) {
        read(u);read(v);
        add(u,v);add(v,u);
    }
    dfs(1);
    int t = dep[N] / 2 - 1;
    u = N;
    while(t--) {u = fa[u];}
    if(N - siz[u] > siz[u]) puts("Fennec");
    else puts("Snuke");
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
    Solve();
}
