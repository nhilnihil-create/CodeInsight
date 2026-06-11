//http://agc010.contest.atcoder.jp/tasks/agc010_c?lang=en

#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;
typedef long long ll;

const int MAXN = 1e5 + 10;
int n, A[ MAXN ], deg[ MAXN ];
vector< int > graph[ MAXN ];
map< pii, ll > edge;
bool visited[ MAXN ];


bool check( int u ){
	if( graph[ u ].size() == 1 ) return edge[ make_pair( min( u, graph[ u ][ 0 ] ), max( u, graph[ u ][ 0 ] ) ) ] == A[ u ];
	ll sum = 0;
	for( int i = 0; i < graph[ u ].size(); ++i ){
		ll val = edge[ make_pair( min( u, graph[ u ][ i ] ), max( u, graph[ u ][ i ] ) ) ];
		if( val > A[ u ] ) return false;
		sum += val;
	}
	return sum == (A[ u ] << 1);
}

int main(){
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) scanf( "%d", &A[i] );
	for( int i = 1, a, b; i < n; ++i ){
		scanf( "%d%d", &a, &b );
		graph[ a ].push_back( b );
		graph[ b ].push_back(  a );
		++deg[ a ]; ++deg[ b ];
	}
	queue< int > q;
	for( int i = 1; i <= n; ++i )
		if( deg[ i ] == 1 ) q.push( i );

	bool flag = true;

	while( flag && !q.empty() ){
		int u = q.front(); q.pop();
		//cout << u << endl;
		visited[ u ] = true;
		ll sum = 0; int v = -1;
		for( int i = 0; i < graph[ u ].size(); ++i ){
			int ne = graph[ u ][ i ];
			if( visited[ ne ] ) sum += edge[ make_pair( min( u, ne ), max( ne, u ) ) ];
			else v = ne;
		}
		if( v != -1 ){
			--deg[ v ];
			if( deg[ v ] == 1 ) q.push( v );
			if( graph[ u ].size() == 1 ){
				edge[ make_pair( min( u, v ), max( u, v ) ) ] = A[ u ];
			}
			else{
				if( (A[ u ] << 1) < sum ) flag = false;
				else edge[ make_pair( min( u, v ), max( u, v ) ) ] = (A[ u ] << 1) - sum;
			}
		}
	}

	/*for( map< pii, ll >::iterator it = edge.begin(); it != edge.end(); ++it ){
		cout << (it->first).first << '-' << (it->first).second << ": " << it->second << endl;
	}*/

	if( flag )
		for( int i = 1; i <= n && flag; ++i )
			flag  = check( i );

	if( flag ) puts( "YES" );
	else puts( "NO" );

	return 0;
}