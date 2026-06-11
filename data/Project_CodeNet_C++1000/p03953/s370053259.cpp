#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100010;
int _w;

int n, x[N], m, a[N], p[N];
ll k, d[N];

template<typename T>
void mul( T *a, int *b, T *_c ) {
	static T c[N];
	for( int i = 1; i < n; ++i )
		c[i] = a[b[i]];
	for( int i = 1; i < n; ++i )
		_c[i] = c[i];
}

void fpow( int *_a, ll b, int *_c ) {
	static int a[N], c[N];
	for( int i = 1; i < n; ++i ) {
		a[i] = _a[i];
		c[i] = i;
	}
	while(b) {
		if( b & 1 ) mul(c, a, c);
		mul(a, a, a);
		b >>= 1;
	}
	for( int i = 1; i < n; ++i )
		_c[i] = c[i];
}

int main() {
	_w = scanf( "%d", &n );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d", x+i );
	_w = scanf( "%d%lld", &m, &k );
	for( int i = 1; i <= m; ++i )
		_w = scanf( "%d", a+i );
	for( int i = 1; i < n; ++i )
		d[i] = x[i+1] - x[i];
	for( int i = 1; i < n; ++i )
		p[i] = i;
	for( int i = 1; i <= m; ++i ) {
		int u = a[i];
		swap(p[u], p[u-1]);
	}
	fpow(p, k, p), mul(d, p, d);
	d[0] = x[1];
	for( int i = 1; i < n; ++i )
		d[i] += d[i-1];
	for( int i = 0; i < n; ++i )
		printf( "%lld\n", d[i] );
	return 0;
}
