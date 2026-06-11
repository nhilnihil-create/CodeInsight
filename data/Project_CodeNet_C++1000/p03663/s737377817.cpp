#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fpow( ll a, ll b ) {
	ll c = 1;
	while( b-- ) c *= a;
	return c;
}

bool read() {
	char ch;
	scanf( " %c", &ch );
	return ch == 'Y';
}

ll solve1() {
	for( ll i = 1; i <= 10; ++i ) {
		printf( "? %lld\n", fpow(10, i) );
		fflush(stdout);
		bool st = read();
		if( !st ) return i;
	}
	return 0;
}

ll solve2() {
	for( ll i = 9; i >= 1; --i ) {
		printf( "? %lld\n", fpow(10, i) - 1 );
		fflush(stdout);
		bool st = read();
		if( !st ) return i+1;
	}
	return 1;
}

bool check( ll mid ) {
	printf( "? %lld9\n", mid );
	fflush(stdout);
	return read();
}
ll solve3( ll digit ) {
	ll low = fpow(10, digit-1);
	ll high = fpow(10, digit)-1;
	while( low < high ) {
		ll mid = (low + high)/2;
		if( check(mid) ) high = mid;
		else low = mid + 1;
	}
	return low;
}

int main() {
	ll digit = solve1();
	if( !digit ) digit = solve2();
	printf( "! %lld\n", solve3(digit) );
	return 0;
}
