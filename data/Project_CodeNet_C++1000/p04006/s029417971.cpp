#include <cstdio>

typedef long long LL;

const int MAXN = 2000;
int n, x, a[MAXN + 5], mn[MAXN + 5];

template<typename Tp>
inline void chkmin ( Tp& a, const Tp b ) { if ( b < a ) a = b; }

int main () {
	scanf ( "%d %d", &n, &x );
	for ( int i = 1; i <= n; ++ i ) scanf ( "%d", &a[i] ), mn[i] = a[i];
	LL ans = 1ll << 60;
	for ( int k = 0; k < n; ++ k ) {
		LL now = 1ll * k * x;
		for ( int i = 1; i <= n; ++ i ) {
			chkmin ( mn[i], a[( i + k - 1 ) % n + 1] );
			now += mn[i];
		}
		chkmin ( ans, now );
	}
	printf ( "%lld\n", ans );
	return 0;
}