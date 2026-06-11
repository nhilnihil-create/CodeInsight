#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 100005
#define eps 1e-10
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
struct node {
    int to,next;
}E[MAXN * 2];
int sumE,sg[MAXN],head[MAXN];
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u,int fa) {
    sg[u] = 0;
    for(int i = head[u]; i ; i = E[i].next) {
	int v = E[i].to;
	if(v != fa) {
	    dfs(v,u);
	    sg[u] ^= (sg[v] + 1);
	}
    }
}
void Solve() {
    read(N);
    int x,y;
    for(int i = 1 ; i < N ; ++i) {
	read(x);read(y);
	add(x,y);add(y,x);
    }
    dfs(1,0);
    if(sg[1]) puts("Alice");
    else puts("Bob");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
