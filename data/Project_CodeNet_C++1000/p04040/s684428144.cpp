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
const int MOD = 1000000007;
int H,W,A,B;
int fac[1000005],invfac[1000005];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
int fpow(int x,int c) {
    int res = 1,t = x;
    while(c) {
	if(c & 1) res = mul(res,t);
	t = mul(t,t);
	c >>= 1;
    }
    return res;
}
int C(int n,int m) {
    return mul(fac[n],mul(invfac[m],invfac[n - m]));
}
void update(int &x,int y) {
    x = inc(x,y);
}
int Way(int x1,int y1,int x2,int y2) {
    return C(abs(y2 - y1) + abs(x2 - x1),abs(x2 - x1));
}
void Solve() {
    read(H);read(W);read(A);read(B);
    fac[0] = 1;
    for(int i = 1 ; i <= 1000000 ; ++i) fac[i] = mul(fac[i - 1],i);
    invfac[1000000] = fpow(fac[1000000],MOD - 2);
    for(int i = 999999 ; i >= 0 ; --i) invfac[i] = mul(invfac[i + 1],i + 1);
    int ans = 0;
    while(1) {
	++A;++B;
	if(A > H || B > W) break;
	update(ans,mul(Way(H,1,A,B),Way(A,B,1,W)));
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
