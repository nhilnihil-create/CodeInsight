#include <cstring>
#include <algorithm>
#include <cstdio>
#include <utility>

using std::pair;
typedef pair<int,int> pii;
const int N = 100010;
const int M = 11;
int _w;

int n, m, q, v[N], d[N], c[N], ans[N];

namespace G {
	int head[N], nxt[N*2], to[N*2], eid;
	void init() {
		eid = 0;
		memset(head, -1, sizeof head);
	}
	void link( int u, int v ) {
		to[eid] = v, nxt[eid] = head[u], head[u] = eid++;
		to[eid] = u, nxt[eid] = head[v], head[v] = eid++;
	}
}

int vis[N][M];
pii que[N*M];
int begin, end;

bool check( int u, int d ) {
	for( int i = d; i < M; ++i )
		if( vis[u][i] ) return true;
	return false;
}

void solve( int s, int d, int c ) {
	using namespace G;
	if( check(s, d) ) return;
	begin = end = 0, que[end++] = pii(s, d), vis[s][d] = 1;
	while( begin != end ) {
		pii o = que[begin++];
		int u = o.first, d = o.second-1;
		if( !ans[u] ) ans[u] = c;
		if( d == -1 ) continue;
		for( int i = head[u]; ~i; i = nxt[i] ) {
			int v = to[i];
			if( check(v, d) ) continue;
			vis[v][d] = 1, que[end++] = pii(v, d);
		}
	}
}

int main() {
	_w = scanf( "%d%d", &n, &m );
	G::init();
	for( int i = 0; i < m; ++i ) {
		int u, v;
		_w = scanf( "%d%d", &u, &v );
		G::link(u, v);
	}
	_w = scanf( "%d", &q );
	for( int i = 1; i <= q; ++i )
		_w = scanf( "%d%d%d", v+i, d+i, c+i );
	for( int i = q; i >= 1; --i )
		solve( v[i], d[i], c[i] );
	for( int i = 1; i <= n; ++i )
		printf( "%d\n", ans[i] );
	return 0;
}
