#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 300005
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
int N,M;
int tr[MAXN],ans[MAXN];
pii p[MAXN];
int lowbit(int x) {return x & (-x);}
void insert(int x,int v) {
    ++x;
    while(x <= M + 1) {
	tr[x] += v;
	x += lowbit(x);
    }
}
int query(int x) {
    int v = 0;++x;
    while(x > 0) {
	v += tr[x];
	x -= lowbit(x);
    }
    return v;
}
void Solve() {
    read(N);read(M);
    for(int i = 1 ; i <= N ; ++i) {
	read(p[i].fi);read(p[i].se);
	--p[i].fi;
	insert(p[i].fi,1);insert(p[i].se,-1);
    }
    sort(p + 1,p + N + 1,[](pii a,pii b){return a.se - a.fi < b.se - b.fi;});
    int id = N;
    int cnt = 0;
    for(int i = M ; i >= 1 ; --i) {
	while(id >= 1 && p[id].se - p[id].fi >= i) {
	    insert(p[id].fi,-1);insert(p[id].se,1);
	    ++cnt;--id;
	}
	ans[i] = cnt;
	int t = i;
	while(t <= M) {
	    ans[i] += query(t - 1);
	    t += i;
	}
    }
    for(int i = 1 ; i <= M ; ++i) {out(ans[i]);enter;}
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
