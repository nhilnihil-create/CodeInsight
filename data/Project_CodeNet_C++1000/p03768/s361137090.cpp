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
int head[MAXN],sumE;
int N,M,Q;
int dp[MAXN][11];
int c[MAXN],d[MAXN],v[MAXN];
void add(int u,int v) {
    E[++sumE].to = v;E[sumE].next = head[u];head[u] = sumE;
}
void dfs(int v,int d) {
    if(!d) return;
    for(int i = head[v] ; i ; i = E[i].next) {
	int t = E[i].to;
	if(dp[t][d - 1] < dp[v][d]) {
	    dp[t][d - 1] = dp[v][d];
	    dfs(t,d - 1);
	}
    }
}
void Solve() {
    read(N);read(M);
    int a,b;
    for(int i = 1 ; i <= M ; ++i) {
	read(a);read(b);
	add(a,b);add(b,a);
    }
    read(Q);
    for(int i = 1 ; i <= Q ; ++i) {
	read(v[i]);read(d[i]);read(c[i]);
    }
    for(int i = Q ; i >= 1 ; --i) {
	if(dp[v[i]][d[i]] < i) {
	    dp[v[i]][d[i]] = i;
	    dfs(v[i],d[i]);
	}
    }
    for(int i = 1 ; i <= N ; ++i) {
	int g = 0;
	for(int j = 0 ; j <= 10 ; ++j) {
	    g = max(g,dp[i][j]);
	}
	out(c[g]);enter;
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
