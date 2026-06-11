#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
const int N = 200005 ;
using namespace std ;

int n, L, T, a[N], b[N] ;
struct poi {
	int x, y ;
} c[N] ;


bool cmp(poi a, poi b) {
	return a.x < b.x ;
}

inline int hit(int x, int y) {
	if (b[x] > b[y]) swap(x, y) ;
	int tot = 0 ; double res = T - 0.1 ;
	if ((double) ((a[y] - a[x] + L) % L) <= 2.0 * res) ++ tot, res -= 0.5 * ((a[y] - a[x] + L) % L) ;
	tot += (int) (res / (0.5 * L)) ;
	return tot ;
}

void solve() {
	int u = 1, times = 0, pos = 0, x = b[u] == 1 ? (a[u] + T) % L : ((a[u] - T) % L + L) % L, posx, posy ; 
	if (b[u] & 1) {
		rep(i, 1, n) if (c[i].x == x) {
			pos = i ;
			break ;
		}
	} else {
		rep(i, 1, n) if (c[i].x == x) pos = i ;
	}
	rep(i, 1, n) if (b[i] != b[u]) times += hit(i, u), times %= n ;
	if (b[u] & 1) pos -= times, pos = (pos % n + n) % n ; else
		pos = (pos + times) % n ;
	if (!pos) pos = n ; posx = pos ;
//	printf("x_val: %d\n", x) ;
	u = 2, times = 0, pos = 0, x = b[u] == 1 ? (a[u] + T) % L : ((a[u] - T) % L + L) % L ;
	if (b[u] & 1) {
		rep(i, 1, n) if (c[i].x == x) {
			pos = i ;
			break ;
		}
	} else {
		rep(i, 1, n) if (c[i].x == x) pos = i ;
	}
	rep(i, 1, n) if (b[i] != b[u]) times += hit(i, u), times %= n ;
	if (b[u] & 1) pos -= times, pos = (pos % n + n) % n ; else
		pos = (pos + times) % n ;
	if (!pos) pos = n ; posy = pos ;  
	if (c[posx].x != c[posy].x) {
		rep(i, 1, n) if (c[i].x == c[posx].x) pos = i ;
	} else {
		rep(i, 1, n) if (c[i].x == c[posx].x) {
			pos = i ;
			break ;
		}
	}
	rep(i, pos, n) printf("%d\n", c[i].x) ;
	rep(i, 1, pos - 1) printf("%d\n", c[i].x) ;
}

int main() {
	scanf("%d%d%d", &n, &L, &T) ;
	rep(i, 1, n) {
		scanf("%d%d", &a[i], &b[i]) ;
		c[i].x = b[i] == 1 ? (a[i] + T) % L : ((a[i] - T) % L + L) % L ;
		c[i].y = i ;
	}
	sort(c + 1, c + n + 1, cmp) ;
	if (c[1].x == c[n].x) {
		rep(i, 1, n) printf("%d\n", c[i].x) ;
		return 0 ; 
	}
	solve() ;
	return 0 ; 
}