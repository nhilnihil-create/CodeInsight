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
int N,L,Q;
int x[MAXN],st[MAXN][20];
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(x[i]);
    read(L);read(Q);
    for(int i = 1 ; i <= N ; ++i) {
	int t = upper_bound(x + 1,x + N + 1,x[i] + L) - x - 1;
	st[i][0] = t;
    }
    for(int j = 1 ; j <= 19 ; ++j) {
	for(int i = 1 ; i <= N ; ++i) {
	    st[i][j] = st[st[i][j - 1]][j - 1];
	}
    }
    int a,b;
    for(int i = 1 ; i <= Q ; ++i) {
	read(a);read(b);
	if(a > b) swap(a,b);
	int p = a,ans = 0;
	for(int j = 19 ; j >= 0 ; --j) {
	    if(st[p][j] < b) {
		p = st[p][j];
		ans += (1 << j);
	    }
	}
	++ans;
	out(ans);enter;
    }
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
