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
int N,K,head[MAXN],sumE;
int a[MAXN],ans;
int rem[MAXN];
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u) {
    for(int i = head[u] ; i ; i = E[i].next) {
	int v = E[i].to;
	dfs(v);
	if(rem[v] == K - 1 && u != 1) {++ans;rem[v] = -1;}
	rem[u] = max(rem[u],rem[v] + 1);
    }
}
void Solve() {
    read(N);read(K);
    for(int i = 1 ; i <= N ; ++i) {
	read(a[i]);
    }
    if(a[1] != 1) ++ans;
    for(int i = 2 ; i <= N ; ++i) {
	add(a[i],i);
    }
    dfs(1);
    out(ans);enter;
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
