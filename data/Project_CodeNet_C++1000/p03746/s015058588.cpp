#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define Size(x) ((int)((x).size()))
#define rep(i, l, r) for(int (i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for(int (i) = (r); (i) >= (l); --(i))
#define chkmax(x, y) (x) = max((x), (y))
#define chkmin(x, y) (x) = min((x), (y))
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
inline char gc() {
	static char now[1<<16], *S, *T;
	if(S == T) {T = (S = now) + fread(now, 1, 1<<16, stdin); if(S == T) return EOF;}
	return *S++;
}
#define gc getchar
inline int read() {
	int x = 0, f = 1; char c = gc();
	while(c < '0' || c > '9') {(c ^ '-') ? 0 : (f = 0); c = gc();}
	while(c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = gc();}
	return f ? x : ((~x) + 1);
}
#define N 100010
int n, m;
VI con[N], ans;
bool vis[N];
void dfs(int x, int rt) {
	for (int y : con[x]) {
		if (vis[y] || y == rt) continue ;
		vis[y] = 1; ans.pb(y); dfs(y, rt);
		return ;
	}
}
int main() {
	n = read(); m = read();
	for (int i = 1; i <= m; ++ i) {
		int u = read(), v = read();
		con[u].pb(v);
		con[v].pb(u);
	}
	dfs(1, 1);
	reverse(ans.begin(), ans.end());
	dfs(con[1][0], con[1][0]);
	printf("%d\n", (int)ans.size());
	for (int x : ans) printf("%d ", x);
	puts("");
	return 0;
}