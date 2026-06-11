
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define rep( i, n, m ) for(int i = ( n ); i < ( m ); i++)
typedef struct {
	int to;
	int cost;
} edge;

int main( void ){
	cin.tie( 0 );
	ios::sync_with_stdio( false );
	int N;
	cin >> N;
	vector <vector <edge> > G( N );
	vector <ll> cost( N, -1 );
	rep( i, 0, N - 1 ){		// グラフ定義, 0オリジン
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		G[ a ].push_back( edge{b, c} );
		G[ b ].push_back( edge{a, c} );
	}
	int Q, K; cin >> Q >> K;
	K--;
	cost[ K ] = 0;
	queue <int> que;
	que.push( K );
	while(!que.empty()){	// BFS
		int q = que.front(); que.pop();
		for(auto e:G[ q ]){	// つながってる部屋毎に
			if (cost[ e.to ] != -1)
				continue;
			cost[ e.to ] = cost[ q ] + e.cost;
			que.push( e.to );
		}
	}
	rep( i, 0, Q ){
		int a, b; cin >> a >> b;
		printf("%lld\n", cost[a-1]+cost[b-1]);
	}
}
