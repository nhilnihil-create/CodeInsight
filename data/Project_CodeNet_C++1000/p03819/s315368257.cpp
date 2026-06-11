#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 3e5 + 5 ;
using namespace std ;
int n, m, top = 1, f[N], bit[N] ; vector <int> v[N] ; 
struct poi { int l, r ; } a[N] ;
bool cmp(poi a, poi b) { return a.r > b.r ; }
void put(int x) { for ( ; x <= m; x += x & (- x)) ++ bit[x] ; }
int get(int x) { int ret = 0 ; for ( ; x; x -= x & (- x)) ret += bit[x] ; return ret ; }
int main() {
	scanf("%d%d", &n, &m) ;
	rep(i, 1, n) scanf("%d%d", &a[i].l, &a[i].r) ;
	sort(a + 1, a + n + 1, cmp) ;
	rep(i, 1, m) rep(j, 1, m / i) v[i * j].push_back(i) ;
	for (int i = m; i; -- i) {
		for ( ; top <= n && a[top].r == i ; ++ top) put(a[top].l) ;
		rep(j, 0, (int) v[i].size() - 1) {
			int u = v[i][j] ;
			f[u] += get(i) - get(i - u) ;
		}
	}
	rep(i, 1, m) printf("%d\n", f[i]) ;
	return 0 ;
}