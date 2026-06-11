#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 100005 ;
using namespace std ;

int n, m, a[N], b[N] ;

bool cmp(int x, int y) {
	return (x & 1) > (y & 1) ;
}

int main() {
	scanf("%d%d", &n, &m) ;
	rep(i, 1, m) {
		scanf("%d", &a[i]) ;
	}
	sort(a + 1, a + m + 1, cmp) ;
	if (m > 2 && (a[3] & 1)) {
		printf("Impossible\n") ;
		return 0 ;
	}
	if (m == 1) {
		rep(i, 1, m) printf("%d ", a[i]) ;
		if (n == 1) printf("\n%d\n%d\n", 1, 1) ; else
			printf("\n%d\n%d %d\n", 2, 1, n - 1) ;
		return 0 ;
	}
	if (m > 1) swap(a[2], a[m]) ;
	rep(i, 1, m) printf("%d ", a[i]) ;
	rep(i, 1, m) b[i] = a[i] ;
	-- b[1], ++ b[m] ;
	if (!b[1]) {
		rep(i, 1, m - 1) b[i] = b[i + 1] ;
		-- m ;
	}
	printf("\n%d\n", m) ;
	rep(i, 1, m) printf("%d ", b[i]) ;
	return 0 ;
}