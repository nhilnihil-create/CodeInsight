#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
typedef long long ll;
const int N = 100010;
int _w;

int gcd( int a, int b ) {
	return b ? gcd(b, a%b) : a;
}

int n, a[N];
ll s;

bool solve() {
	int cnt = 0;
	for( int i = 1; i <= n; ++i )
		cnt += a[i] & 1;
	if( cnt > 1 ) return false;
	for( int i = 1; i <= n; ++i )
		if( a[i] & 1 ) {
			if( a[i] == 1 ) return false;
			--a[i];
			break;
		}
	int g = a[1];
	for( int i = 2; i <= n; ++i )
		g = gcd( g, a[i] );
	for( int i = 1; i <= n; ++i )
		a[i] /= g;
	ll s = 0;
	for( int i = 1; i <= n; ++i )
		s += a[i];
	if( s & 1 ) {
		return !solve();
	} else {
		return false;
	}
}

int main() {
	cin >> n;
	for( int i = 1; i <= n; ++i ) {
		cin >> a[i];
		s += a[i];
	}
	if( n == 1 ) {
		puts( a[1] == 1 ? "Second" : "First" );
	} else if( n & 1 ) {
		if( s & 1 ) {
			puts( solve() ? "First" : "Second" );
		} else {
			puts("First");
		}
	} else {
		puts( s % 2 ? "First" : "Second" );
	}
	return 0;
}
