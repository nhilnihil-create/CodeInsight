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
int N,M,head[MAXN],sumE;
int que[MAXN * 2],ql,qr;
bool vis[MAXN];
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void Solve() {
    read(N);read(M);
    int a,b;
    for(int i = 1 ; i <= M ; ++i) {
	read(a);read(b);
	add(a,b);add(b,a);
    }
    ql = N,qr = N - 1;
    que[++qr] = 1;vis[1] = 1;
    while(1) {
	int u = que[qr];
	bool flag = 1;
	for(int i = head[u] ; i ; i = E[i].next) {
	    int v = E[i].to;
	    if(!vis[v]) {
		que[++qr] = v;
		vis[v] = 1;
		flag = 0;break;
	    }
	}
	if(flag) break;
    }
    while(1) {
	int u = que[ql];
	bool flag = 1;
	for(int i = head[u] ; i ; i = E[i].next) {
	    int v = E[i].to;
	    if(!vis[v]) {
		que[--ql] = v;
		vis[v] = 1;
		flag = 0;break;
	    }
	}
	if(flag) break;
    }
    out(qr - ql + 1);enter;
    for(int i = ql ; i <= qr ; ++i) {
	out(que[i]);space;
    }
    enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
