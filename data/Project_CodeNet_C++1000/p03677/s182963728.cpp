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
int N,M;
int a[MAXN];
int64 ans,res;
struct node {
    int L,R;
    int64 a,d;
}tr[MAXN * 4];
void build(int u,int L,int R) {
    tr[u].L = L;tr[u].R = R;
    tr[u].a = tr[u].d = 0;
    if(L == R) return;
    int mid = (L + R) >> 1;
    build(u << 1,L,mid);
    build(u << 1 | 1,mid + 1,R);
}
void addlz(int u,int64 a,int64 d) {
    tr[u].a += a;tr[u].d += d;
}
void pushdown(int u) {
    int l = tr[u].L,m = (tr[u].L + tr[u].R) >> 1,r = tr[u].R;
    addlz(u << 1,tr[u].a,tr[u].d);
    addlz(u << 1 | 1,tr[u].a + (m + 1 - l) * tr[u].d,tr[u].d);
    tr[u].a = tr[u].d = 0;
}
void Add(int u,int ql,int qr,int64 a,int64 d) {
    if(ql > qr) return;
    if(ql == tr[u].L && qr == tr[u].R) {addlz(u,a,d);return;}
    int mid = (tr[u].L + tr[u].R) >> 1;
    pushdown(u);
    if(qr <= mid) Add(u << 1,ql,qr,a,d);
    else if(ql > mid) Add(u << 1 | 1,ql,qr,a,d);
    else {Add(u << 1,ql,mid,a,d),Add(u << 1 | 1,mid + 1,qr,a + (mid + 1 - ql) * d,d);}
}
void Getans(int u) {
    if(tr[u].L == tr[u].R) {res = max(tr[u].a,res);return;}
    pushdown(u);
    Getans(u << 1);Getans(u << 1 | 1);
}
void Solve() {
    read(N);read(M);
    build(1,1,M);
    for(int i = 1 ; i <= N ; ++i) {
	read(a[i]);
    }
    for(int i = 2 ; i <= N ; ++i) {
	if(a[i] > a[i - 1]) {
	    ans += a[i] - a[i - 1];
	    Add(1,a[i - 1] + 1,a[i],0,1);
	}
	else {
	    ans += M - a[i - 1] + a[i];
	    Add(1,a[i - 1] + 1,M,0,1);
	    Add(1,1,a[i],M - a[i - 1],1);
	}
    }
    Getans(1);
    out(ans - res);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
