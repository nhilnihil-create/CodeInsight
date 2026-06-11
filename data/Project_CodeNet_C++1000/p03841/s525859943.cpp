#include <bits/stdc++.h>

using namespace std;
const int N = 510;
const int M = N*N;
int _w;

int n, m, a[M];

struct Node {
	int r, v;
	Node() {}
	Node( int r, int v ):
		r(r), v(v) {}
	bool operator<( const Node &rhs ) const {
		return r > rhs.r;
	}
};
typedef vector<Node>::iterator viter;
vector<Node> v[M];
priority_queue<Node> pq;

int main() {
	cin >> n, m = n*n;
	for( int i = 1; i <= n; ++i ) {
		int x;
		cin >> x, a[x] = i;
		for( int j = 1; j < i; ++j )
			v[1].push_back( Node(x-1, i) );
		for( int j = i+1; j <= n; ++j )
			v[x+1].push_back( Node(m, i) );
	}
	for( int i = 1; i <= m; ++i ) {
		for( viter it = v[i].begin(); it != v[i].end(); ++it )
			pq.push(*it);
		if( !a[i] ) {
			if( pq.empty() ) return puts("No"), 0;
			Node o = pq.top(); pq.pop();
			if( o.r < i ) return puts("No"), 0;
			a[i] = o.v;
		}
	}
	if( !pq.empty() ) return puts("No"), 0;
	puts("Yes");
	for( int i = 1; i <= m; ++i )
		printf( "%d ", a[i] );
	puts("");
	return 0;
}
