#include <cstring>
#include <algorithm>
#include <cstdio>

using std::sort;
const int N = 100010;
int _w;

int n, l, t, x[N], w[N], y[N];

bool all2() {
	for( int i = 1; i <= n; ++i )
		if( w[i] == 1 ) return false;
	return true;
}
void solve2() {
	t %= l;
	for( int i = 1; i <= n; ++i )
		printf( "%d\n", (x[i] - t + l) % l );
}

void solve1( int s ) {
	int go = 0;
	for( int i = 1; i <= n; ++i )
		if( w[i] == 2 ) {
			int d = (x[i] - x[s] + l) % l;
			int tt = t * 2;
			if( tt > d ) {
				tt -= d, ++go;
				go += tt/l;
				if( tt % l == 0 ) --go;
			}
		}
	go %= n;
	int end = s + go;
	if( end > n ) end -= n;
	int pos;
	t %= l;
	for( int i = 1; i <= n; ++i ) {
		if( w[i] == 1 ) {
			y[i] = (x[i] + t) % l;
		} else {
			y[i] = (x[i] - t + l) % l;
		}
		if( i == s ) pos = y[i];
	}
	sort(y+1, y+n+1);
	for( int i = 1; i <= n; ++i )
		if( y[i] == pos ) {
			s = i;
			break;
		}
	s -= end-1;
	if( s < 1 ) s += n;
	for( int i = 0; i < n; ++i ) {
		int p = s+i;
		if( p > n ) p -= n;
		printf( "%d\n", y[p] );
	}
}

int main() {
	_w = scanf( "%d%d%d", &n, &l, &t );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d%d", x+i, w+i );
	if( all2() ) solve2();
	else {
		for( int i = 1; i <= n; ++i )
			if( w[i] == 1 ) {
				solve1(i);
				break;
			}
	}
	return 0;
}
