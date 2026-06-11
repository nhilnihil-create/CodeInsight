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
int X[MAXN],cnt[MAXN],a[MAXN],p[MAXN];
void Solve() {
    read(N);read(M);
    for(int i = 1 ; i <= N ; ++i) {
	read(X[i]);cnt[X[i]]++;
    }
    int ans = 0;
    for(int i = 1 ; i <= 100000 ; ++i) {
	ans += cnt[i] / 2;
	p[i % M] += cnt[i] / 2;
	a[i % M] += cnt[i] % 2;
    }
    for(int i = 0 ; i < M ; ++i) {
	if(i > M - i) break;
	if(i == M - i || i == 0) ans += a[i] / 2;
	else {
	    int t = min(a[i],a[M - i]);
	    a[i] -= t;a[M - i] -= t;
	    if(a[i]) {
		t += min(p[M - i],a[i] / 2);
	    }
	    else if(a[M - i]) {
		t += min(p[i],a[M - i] / 2);
	    }
	    ans += t;
	}
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
