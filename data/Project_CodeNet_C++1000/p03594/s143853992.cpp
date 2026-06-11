#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 510;
const char *c = "RGBY";
int _wno;

int n, m, d, a[MAXN][MAXN];

bool inside( int x, int y ) {
	return x >= 1 && y >= 1 && x <= n && y <= m;
}

void assign( int x, int y, int c ) {
	if( inside(x, y) ) a[x][y] = c;
}

void paint( int x, int y, int c ) {
	int d2 = d>>1;
	for( int i = 1; i <= d2; ++i )
		for( int j = d2; j > d2-i; --j ) {
			int i2 = d-i, j2 = d-j+1;
			assign( x+i-1, y+j-1, c );
			assign( x+i-1, y+j2-1, c );
			assign( x+i2-1, y+j-1, c );
			assign( x+i2-1, y+j2-1, c );
		}
}

void solve_even() {
	int d2 = d>>1;
	for( int i = 1; i <= n; i += d+d )
		for( int j = 1; j <= m; j += d+d )
			paint(i, j, 0);
	for( int i = d+1; i <= n; i += d+d )
		for( int j = d+1; j <= m; j += d+d )
			paint(i, j, 0);
	for( int i = 1; i <= n; i += d+d )
		for( int j = d+1; j <= m; j += d+d )
			paint(i, j, 1);
	for( int i = d+1; i <= n; i += d+d )
		for( int j = 1; j <= m; j += d+d )
			paint(i, j, 1);
	for( int i = 1-d2; i <= n; i += d+d )
		for( int j = 1-d2; j <= m; j += d+d )
			paint(i, j, 2);
	for( int i = 1+d2; i <= n; i += d+d )
		for( int j = 1+d2; j <= m; j += d+d )
			paint(i, j, 2);
	for( int i = 1-d2; i <= n; i += d+d )
		for( int j = 1+d2; j <= m; j += d+d )
			paint(i, j, 3);
	for( int i = 1+d2; i <= n; i += d+d )
		for( int j = 1-d2; j <= m; j += d+d )
			paint(i, j, 3);
}

void solve_odd() {
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++j )
			a[i][j] = (i+j)&1;
}

int main() {
	_wno = scanf( "%d%d%d", &n, &m, &d );
	memset( a, -1, sizeof(a) );
	if( d & 1 ) solve_odd();
	else solve_even();
	for( int i = 1; i <= n; ++i, puts("") )
		for( int j = 1; j <= m; ++j )
			putchar( c[a[i][j]] );
	return 0;
}
