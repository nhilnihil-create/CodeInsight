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
int N,head[MAXN],sumE,deg[MAXN];
int64 up[MAXN],A[MAXN];
bool flag = 0;
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u,int fa) {
    if(deg[u] == 1) {up[u] = A[u];return;}
    for(int i = head[u] ; i ; i = E[i].next) {
	int v = E[i].to;
	if(v != fa) {
	    dfs(v,u);
	    if(flag) return;
	}
    }
    int64 md = 0;
    for(int i = head[u] ; i ; i = E[i].next) {
	int v = E[i].to;
	if(v != fa) {
	    md = max(up[v],md);
	    up[u] += up[v];
	}
    }
    if(up[u] == 0 && A[u] == 0) return;
    int64 k = min(up[u] / 2,up[u] - md);
    if(up[u] - k > A[u] || up[u] < A[u]) {flag = 1;return;}
    up[u] = A[u] - (up[u] - A[u]);
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(A[i]);
    int a,b;
    for(int i = 1 ; i < N ; ++i) {
	read(a);read(b);
	deg[a]++;deg[b]++;
	add(a,b);add(b,a);
    }
    if(N == 2) {
	if(A[1] == A[2]) puts("YES");
	else puts("NO");
	return;
    }
    int rt = 0;
    for(int i = 1 ; i <= N ; ++i) {
	if(deg[i] > 1) rt = i;
    }
    dfs(rt,0);
    if(flag == 1 || up[rt] != 0) puts("NO");
    else puts("YES");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
