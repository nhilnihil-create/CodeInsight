#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g( N );
	for( int i = 0; i < M; i++ ) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back( b );
		g[b].push_back( a );
	}

	vector<int> v( N );
	typedef pair<int, int> P;
	queue<P> que;
	que.push( P( 0, 0 ) );
	v[0] = 1;
	string ans = "IMPOSSIBLE";
	while( !que.empty() ) {
		int d, x;
		tie( d, x ) = que.front();
		que.pop();
		if( x == N - 1 ) {
			ans = "POSSIBLE";
			break;
		}
		if( d >= 2 ) continue;
		for( int e : g[x] ) {
			if( v[e] ) continue;
			que.push( P( d + 1, e ) );
			v[e] = 1;
		}
	}

	cout << ans << endl;
}
