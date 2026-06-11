#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 100005
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
    	res = res * 10 +c - '0';
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
int N,sumE,head[MAXN],dep[MAXN];
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u) {
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        dfs(v);
    }
    vector<int> sec;
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        sec.pb(dep[v]);
    }
    sort(sec.begin(),sec.end());
    for(auto t : sec) {
        dep[u] = max(dep[u],t) + 1;
    }
}
void Solve() {
    read(N);
    int f;
    for(int i = 2 ; i <= N ; ++i) {
        read(f);
        add(f,i);
    }
    dfs(1);
    out(dep[1]);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
