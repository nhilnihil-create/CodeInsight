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
int x[505], a[2500005];
int n, vs[2500005];
int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &x[i]), a[x[i]] = i, vs[x[i]] = 1;
	int p = 0;
	rep(i, 1, n * n) {
		if(vs[i] == 0) continue;
		int y = a[i] - 1;
		while(y--) {
			++p;
			while(a[p]) ++p;
			a[p] = a[i];
		}
		if(p >= i) {puts("No"); return 0;}
	}
	rep(i, 1, n * n) {
		if(vs[i] == 0) continue;
		int y = n - a[i];
		
		while(y--) {
			++p;
			while(a[p]) ++p;
			if(p <= i) {puts("No"); return 0;}
			a[p] = a[i];
		}
	}
	puts("Yes");
	rep(i, 1, n * n) printf("%d ", a[i]);
	return 0;
}
