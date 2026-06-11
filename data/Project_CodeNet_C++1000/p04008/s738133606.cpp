#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int _w;

int n, k, a[N], ans;

namespace Tree {
	int head[N], nxt[N], to[N], eid;
	void init() {
		eid = 0;
		memset(head, -1, sizeof head);
	}
	void link( int u, int v ) {
		to[eid] = v, nxt[eid] = head[u], head[u] = eid++;
	}
}

int dfs( int u, int fa ) {
	using namespace Tree;
	int d = 0;
	for( int i = head[u]; ~i; i = nxt[i] ) {
		int v = to[i];
		if( v == fa ) continue;
		d = max(d, dfs(v, u) + 1);
	}
	if( d == k-1 ) {
		ans += fa != 1 && fa != 0;
		return -1;
	} else {
		return d;
	}
}

int main() {
	_w = scanf( "%d%d", &n, &k );
	Tree::init();
	for( int i = 1; i <= n; ++i ) {
		_w = scanf( "%d", a+i );
		if( i != 1 ) Tree::link( a[i], i );
	}
	if( a[1] != 1 ) ++ans;
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
