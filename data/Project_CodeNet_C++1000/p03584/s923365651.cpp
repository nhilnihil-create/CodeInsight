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
int N,K;
int A[MAXN],B[MAXN];
int64 ans;
int lowbit(int x) {
	return x & (-x);
}
void Calc(int v) {
	int64 res = 0;
	for(int i = 1 ; i <= N ; ++i) {
		if((v & A[i]) == A[i]) res += B[i];
	}
	ans = max(ans,res);
}
void Solve() {
	read(N);read(K);
	for(int i = 1 ; i <= N ; ++i) {
		read(A[i]);read(B[i]);
	}
	Calc(K);
	while(K) {
		int t = lowbit(K);
		int h = K - 1;
		K -= t;
		Calc(h);
	}
	out(ans);enter;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	Solve();
}
