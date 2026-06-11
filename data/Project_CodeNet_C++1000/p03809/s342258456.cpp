#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100010;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x*10)+(ch^48);
	return x * f;
}

int st[MAXN], to[MAXN<<1];
int nxt[MAXN<<1], e;
inline void Add(int u, int v) {
	to[++e] = v, nxt[e] = st[u];
	st[u] = e;
}

int n, a[MAXN];
int deg[MAXN], r;
ll val[MAXN];

void dfs(int u, int fa) {
	int i;
	if(deg[u] == 1) {
		val[u] = a[u];
		return;
	}
	for(i = st[u]; i; i = nxt[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
	}
	ll S = 0, K = 0;
	for(i = st[u]; i; i = nxt[i]) {
		int v = to[i];
		if(v == fa) continue;
		S += val[v];
		K = max(K, val[v]);
		//val[u] -= val[v];
	}
	val[u] = a[u]*2-S;
	if(val[u] < 0 || S-a[u] < 0) {
		printf("NO\n");
		exit(0);
	}
	if(a[u] < K) {
		printf("NO\n");
		exit(0);
	}
}

int main() {
	int i;

	n = read();

	for(i = 1; i <= n; i++) a[i] = read();
	for(i = 1; i < n; i++) {
		int u = read(), v = read();
		Add(u, v), Add(v, u);
		deg[u]++, deg[v]++;
	}
	//for(i = 1; i <= n; i++) printf("%d ", deg[i]);
	if(n == 2) {
		if(a[1] == a[2]) printf("YES\n");
		else printf("NO\n");
		return 0;
	}

	for(r = 1; r <= n; r++) 
		if(deg[r] != 1) break;

	dfs(r, 0);
	/*printf("%d\n", r);
	for(i = 1; i <= n; i++) printf("%lld ", val[i]);
	printf("\n");*/
	if(val[r] == 0) {
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}
