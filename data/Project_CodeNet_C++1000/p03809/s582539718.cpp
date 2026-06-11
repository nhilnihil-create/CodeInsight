#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using std::max;
typedef long long ll;
const int N = 100010;
int _w;

int n, a[N], d[N];

namespace Tree {
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

ll f[N];

void dfs( int u, int fa ) {
	using namespace Tree;
	if( d[u] == 1 ) {
		f[u] = a[u];
	} else {
		ll s = 0, mx = 0;
		for( int i = head[u]; ~i; i = nxt[i] ) {
			int v = to[i];
			if( v == fa ) continue;
			dfs(v, u);
			s += f[v];
			mx = max( mx, f[v] );
		}
		if( s < a[u] || s > a[u] + a[u] )
			puts("NO"), exit(0);
		ll t = s - a[u];
		f[u] = a[u] - t;
		t += t;
		if( mx > s-mx ) {
			ll t2 = s-mx;
			t2 += t2;
			if( t2 < t ) puts("NO"), exit(0);
		} else {
			ll t2 = s % 2 ? s-1 : s;
			if( t2 < t ) puts("NO"), exit(0);
		}
	}
}

int main() {
	_w = scanf( "%d", &n );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d", a+i );
	Tree::init();
	for( int i = 0; i < n-1; ++i ) {
		int u, v;
		_w = scanf( "%d%d", &u, &v );
		Tree::link(u, v);
		++d[u], ++d[v];
	}
	if( n == 2 ) {
		puts( a[1] == a[2] ? "YES" : "NO" );
		return 0;
	}
	for( int i = 1; i <= n; ++i )
		if( d[i] > 1 ) {
			dfs(i, 0);
			puts( f[i] ? "NO" : "YES" );
			break;
		}
	return 0;
}
