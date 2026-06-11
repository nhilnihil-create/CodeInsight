#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
#define V std::vector
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m; bool vis[kN];
std::list <int> path;
V <int> E[kN];
void Add(int u, int v) {
	E[u].push_back(v); E[v].push_back(u);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
			if(i == 1) {
				vis[u] = vis[v] = true;
				path.push_back(u); path.push_back(v);
			}
		}
		while(true) {
			int cur = path.front(); bool flag = false;
			for(auto i : E[cur]) if(!vis[i]) {
				vis[i] = true; flag = true;
				path.push_front(i);
				break;
			}
			if(!flag) break;
		}
		while(true) {
			int cur = path.back(); bool flag = false;
			for(auto i : E[cur]) if(!vis[i]) {
				vis[i] = true; flag = true;
				path.push_back(i);
				break;
			}
			if(!flag) break;
		}
		int len = 0;
		for(auto i : path) ++len;
		printf("%d\n", len);
		for(auto i : path) printf("%d ", i);
		printf("\n");
	} return 0;
}