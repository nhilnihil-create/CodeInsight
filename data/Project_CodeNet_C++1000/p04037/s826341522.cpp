#include<bits/stdc++.h> 
#define Pair pair<int, double>
#define MP(x, y) make_pair(x, y)
#define fi first
#define se second
//#define int long long 
#define LL long long 
#define Fin(x) {freopen(#x".in","r",stdin);}
#define Fout(x) {freopen(#x".out","w",stdout);}
using namespace std;
const int MAXN = 1e6 + 10, mod = 998244353, INF = 2e9 + 10;
const double eps = 1e-9;
template <typename A, typename B> inline bool chmin(A &a, B b){if(a > b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline bool chmax(A &a, B b){if(a < b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline LL add(A x, B y) {if(x + y < 0) return x + y + mod; return x + y >= mod ? x + y - mod : x + y;}
template <typename A, typename B> inline void add2(A &x, B y) {if(x + y < 0) x = x + y + mod; else x = (x + y >= mod ? x + y - mod : x + y);}
template <typename A, typename B> inline LL mul(A x, B y) {return 1ll * x * y % mod;}
template <typename A, typename B> inline void mul2(A &x, B y) {x = (1ll * x * y % mod + mod) % mod;}
template <typename A> inline void debug(A a){cout << a << '\n';}
template <typename A> inline LL sqr(A x){return 1ll * x * x;}
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, a[MAXN];
signed main() {
	N = read();
	for(int i = 1; i <= N; i++) a[i] = read();
	sort(a + 1, a + N + 1, greater<int>());
	for(int i = 1; i <= N; i++) {
		if(i + 1 > a[i + 1]) {
			if((a[i] - i) & 1) {puts("First"); return 0;}
			int j;
			for(j = i + 1; a[j] == i; j++); 
			if(!((j - i) & 1)) {puts("First"); return 0;}
			puts("Second"); return 0;
		}
	}
	return 0;
}
/*
10 3
aaaabbbbab
7 7 3 9 10 6 7 6 6 1
2 6 2
1 3 1
2 9 1
*/