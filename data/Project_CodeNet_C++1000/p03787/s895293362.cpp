#include <cstring>
#include <algorithm>
#include <cstdio>

typedef long long ll;
const int N = 1000010;
int _w;

int n, m;

namespace G {
	int head[N], nxt[N], to[N], eid;
	void init() {
		eid = 0;
		memset(head, -1, sizeof head);
	}
	void link( int u, int v ) {
		to[eid] = v, nxt[eid] = head[u], head[u] = eid++;
		to[eid] = u, nxt[eid] = head[v], head[v] = eid++;
	}
}

int cnt[3], vis[N], q[N], begin, end;

int bfs( int s ) {
	using namespace G;
	begin = end = 0, q[end++] = s, vis[s] = 1;
	int type = 2;
	while( begin != end ) {
		int u = q[begin++];
		for( int i = head[u]; ~i; i = nxt[i] ) {
			int v = to[i];
			if( vis[v] == vis[u] ) {
				type = 1;
			} else if( !vis[v] ) {
				vis[v] = 3 - vis[u];
				q[end++] = v;
			}
		}
	}
	if( end == 1 ) return 0;
	else return type;
}

void solve() {
	ll ans = 0;
	if( cnt[0] ) {
		int m = n - cnt[0];
		ans += 1LL*n*n - 1LL*m*m;
	}
	if( cnt[1] ) {
		ans += 1LL * cnt[1] * (cnt[1] + cnt[2]);
	}
	if( cnt[2] ) {
		ans += 1LL * cnt[2] * (cnt[1] + cnt[2] * 2);
	}
	printf( "%lld\n", ans );
}

int main() {
	_w = scanf( "%d%d", &n, &m );
	G::init();
	for( int i = 0; i < m; ++i ) {
		int u, v;
		_w = scanf( "%d%d", &u, &v );
		G::link(u, v);
	}
	for( int i = 1; i <= n; ++i )
		if( !vis[i] )
			cnt[bfs(i)]++;
	solve();
	return 0;
}
