#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(x, a, b) for(int x = (a); x <= (b); ++x)
#define rop(x, a, b) for(int x = (a); x < (b); ++x)
#define per(x, a, b) for(int x = (a); x >= (b); --x)
using namespace std;
typedef long long LL;
typedef double DB;
LL x;
__int128 n, a[100005], b[100005], as, T;
int main() {
	scanf("%lld", &x);
	n = x;
	rep(i, 1, n) {
		scanf("%lld", &x);
		b[i] = x;
		a[i] = b[i] - b[i - 1];
	}
	rep(i, 1, n) as = as + a[i] * (n - i + 1);
	if((as % (n * (n + 1) / 2) + (n * (n + 1) / 2)) % (n * (n + 1) / 2)) {puts("NO"); return 0;}
	as = as / (n * (n + 1) / 2);
	rep(i, 2, n) {
		if(as < a[i]) {puts("NO"); return 0;}
		if(as % n != (a[i] % n + n) % n) {puts("NO"); return 0;} 
	}
	int T = 0;
	rep(i, 2, n) {
		T = T - a[i];
	}
	if(as < T) {puts("NO"); return 0;}
	puts("YES"); 
	return 0;
}
