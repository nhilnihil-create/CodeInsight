#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100010;
const int MAXM = 200010;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x*10)+(ch^48);
	return x * f;
}

int st[MAXN], to[MAXM<<1];
int e, nxt[MAXM<<1];
inline void Add(int u, int v) {
	to[++e] = v, nxt[e] = st[u];
	st[u] = e;
}

int n, m, size;
bool vis[MAXN], col[MAXN];
ll ans;

inline bool dfs(int u) {
	vis[u] = true, size++;
	bool res = false;
	int i;
	for(i = st[u]; i; i = nxt[i]) {
		int v = to[i];
		if(vis[v]) {
			if(col[v] == col[u]) res = true;
			continue;
		}
		col[v] = col[u]^1, res |= dfs(v);
	}
	return res;
}

int main() {
	int i;
	n = read(), m = read();
	for(i = 1; i <= m; i++) {
		int u = read(), v = read();
		Add(u, v), Add(v, u);
	}
	ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
	bool oc;
	for(i = 1; i <= n; i++) {
		if(vis[i]) continue;
		size = 0, oc = dfs(i);
		if(size == 1) cnt2++;
		else if(oc) cnt1++;
		else cnt0++;
	}
	ans = cnt2*((n-cnt2)<<1)+cnt2*cnt2;
	ans += cnt0*cnt0*2+cnt1*cnt1+cnt0*cnt1*2;
	printf("%lld\n", ans);
	return 0;
}
