#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 2005
#define MOD 99994711
#define ba 47
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
int N,sumE,head[MAXN],dep[MAXN],K,fa[MAXN],ans,cnt[MAXN];
vector<pii > Ed;
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u) {
    cnt[dep[u]]++;
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        if(v != fa[u]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
}
void Solve() {
    read(N);read(K);
    int a,b;
    for(int i = 1 ; i < N ; ++i) {
    	read(a);read(b);
    	add(a,b);add(b,a);
        Ed.pb(mp(a,b));
    }
    int ans = N;
    for(int i = 1 ; i <= N ; ++i) {
        int u = i;
        fa[u] = 0;dep[u] = 0;
        memset(cnt,0,sizeof(cnt));
        dfs(u);
        int res = 0;
        for(int j = K / 2 + 1 ; j <= N ; ++j) res += cnt[j];
        ans = min(ans,res);
    }
    if(K % 2 == 0) --K;
	for(auto t : Ed) {
        fa[t.fi] = t.se;fa[t.se] = t.fi;dep[t.fi] = dep[t.se] = 0;
        memset(cnt,0,sizeof(cnt));
        dfs(t.fi);dfs(t.se);
        int res = 0;
        for(int i = K / 2 + 1 ; i <= N ; ++i) res += cnt[i];
        ans = min(ans,res);
    }
    out(ans);enter;
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
