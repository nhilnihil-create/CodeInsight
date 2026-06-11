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
int N;
int a[MAXN];
vector<pii > p;
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(a[i]);
    sort(a + 1,a + N + 1,[](int c,int d){return c > d;});
    for(int i = 1 ; i <= N ; ++i) {
	if(a[i + 1] != a[i]) {
	    p.pb(mp(i,i - a[i]));
	}
    }
    int c = -1,d = p.size();
    
    while(c < (int)p.size() - 1 && p[c + 1].se <= 0) ++c;
    while(d > 0 && p[d - 1].se >= 0) --d;
    if(c >= 0) {
	if(p[c].se == 0) {puts("Second");return;}
    }
    bool f = 0;
    if(c >= 0 && d < (int)p.size()) {
	if(!((abs(p[c].se) ^ abs(p[d].se)) & 1)) {
	    f = (abs(p[c].se) & 1);
	}
	else {
	    int t = p[c].fi - a[p[c].fi + 1];
	    if(t == 0) f = 1;
	    else if(0 < t) {f |= abs(p[c].se) & 1;}
	    else f |= abs(p[d].se) & 1;
	}
    }
    else if(c >= 0) { f |= abs(p[c].se) & 1;}
    else if(d < (int)p.size()) {f |= p[d].se & 1;}
    if(f) puts("First");
    else puts("Second");
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
