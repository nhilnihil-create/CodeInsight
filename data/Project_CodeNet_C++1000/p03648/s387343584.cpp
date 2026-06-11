#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
int nowarn;

const int n = 50;
ll k, a[n];

void simulate() {
	int p = int(max_element(a, a+n) - a);
	for( int i = 0; i < n; ++i )
		a[i] += (i == p ? -n : 1);
}

int main() {
	nowarn = scanf( "%lld", &k );
	ll op = k / n + 1;
	for( int i = 0; i < n; ++i ) a[i] = n-1 + op;
	for( op *= n; op > k; --op ) simulate();
	printf( "%d\n", n );
	for( int i = 0; i < n; ++i ) printf( "%lld ", a[i] );
	puts("");
	return 0;
}
