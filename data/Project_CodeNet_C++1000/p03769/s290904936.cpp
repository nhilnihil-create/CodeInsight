#include <cstring>
#include <algorithm>
#include <cstdio>
#include <utility>

using std::pair;
typedef long long ll;
typedef pair<int,ll> pil;
const int N = 110;
int _w;

ll n;
pil a[N];
int m;

void solve() {
	int p = 0;
	ll s = 1;
	for( int i = 1; i <= m; ++i ) {
		s += a[i].second;
		if( s <= n ) p = i;
	}
	s = 0;
	for( int i = 0; i <= p; ++i ) s += a[i].second;
	++p;
	for( int i = m+1; i > p; --i ) a[i] = a[i-1];
	a[p] = pil(++m, s);
	n -= s;
}

int main() {
	_w = scanf( "%lld", &n );
	a[0] = pil(0, 1);
	while(n) solve();
	printf( "%d\n", m*2 );
	for( int i = 1; i <= m; ++i )
		printf( "%d ", a[i].first );
	for( int i = 1; i <= m; ++i )
		printf( "%d ", i );
	puts("");
	return 0;
}
