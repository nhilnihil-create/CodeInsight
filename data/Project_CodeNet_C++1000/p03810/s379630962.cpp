#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define rep(x, a, b) for(int x = (a); x <= (b); ++x)
#define rop(x, a, b) for(int x = (a); x < (b); ++x)
#define per(x, a, b) for(int x = (a); x >= (b); --x)
using namespace std;
typedef long long LL;
typedef double DB;
int a[100005], pr[100005], sf[100005];
int n;
int dfs() {
	LL K = 0;
	rep(i, 1, n) K += a[i] - 1;
	if(K & 1) return 1;
	rep(i, 1, n) pr[i] = __gcd(pr[i - 1], a[i]);
	per(i, n, 1) sf[i] = __gcd(sf[i + 1], a[i]);
	rep(i, 1, n) {
		if(a[i] == 1) continue;
		K = __gcd(__gcd(pr[i - 1], sf[i + 1]), a[i] - 1);
		if(K != 1) {
			--a[i];
			rep(j, 1, n) a[j] /= K; 
			int bj = dfs();
			rep(j, 1, n) a[j] *= K;
			++a[i];
			return bj ^ 1;
		}
	}
	return 0;
}
signed main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
	}
	if(n == 1) puts(a[1] == 1 ? "Second" : "First");
	else if(n == 2) puts("First");
	else puts(dfs() ? "First" : "Second");
	return 0;
}
