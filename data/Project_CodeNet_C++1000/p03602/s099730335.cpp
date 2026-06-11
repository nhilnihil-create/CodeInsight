#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 100005
#define eps 1e-12
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
int64 A[305][305];
int64 B[305][305],ans;
pii p[100005];
int tot,N;
void Solve() {
	read(N);
	for(int i = 1 ; i <= N ; ++i) {
		for(int j = 1 ; j <= N ; ++j) {
			read(A[i][j]);
			if(i != j) B[i][j] = 1e16;
			if(i < j) p[++tot] = mp(i,j);
		}
	}
	sort(p + 1,p + tot + 1,[](pii a,pii b){return A[a.fi][a.se] < A[b.fi][b.se];});
	for(int i = 1 ; i <= tot ; ++i) {
		int u = p[i].fi,v = p[i].se;
		for(int j = 1 ; j <= N ; ++j) {
			B[u][v] = min(B[u][j] + B[j][v],B[u][v]);
		}
		B[v][u] = B[u][v];
		if(B[u][v] < A[u][v]) {puts("-1");return;}
		if(B[u][v] == A[u][v]) continue;
		ans += A[u][v];
		B[u][v] = B[v][u] = A[u][v];
	}
	out(ans);enter;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	Solve();
}
