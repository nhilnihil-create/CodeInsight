#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int _w;

int n, a[N];

int main() {
	_w = scanf( "%d", &n );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d", a+i );
	sort(a+1, a+n+1, greater<int>());
	int p;
	for( int i = 1; i <= n; ++i )
		if( a[i] >= i ) p = i;
	int q;
	for( int i = 1; i <= n; ++i )
		if( a[i] >= p ) q = i;
	int c1 = (a[p] - p) & 1;
	int c2 = (q - p) & 1;
	puts( c1 || c2 ? "First" : "Second" );
	return 0;
}
