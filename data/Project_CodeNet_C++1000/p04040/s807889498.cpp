//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define M 1000000007
typedef long T;
//#include "math/mod.h"

/* ax+by=gcd(a,b) */
T gcd_ext(T a, T b, T *x, T *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	T x1, y1;
	T gcd = gcd_ext(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
}

T mod_norm(T a, T m) {
	return (a % m + m) % m;
}

T mod_sub(T a, T b, T m) {
	return mod_norm(a-b, m);
}

T mod_add(T a, T b, T m) {
	return mod_norm(a+b, m);
}

T mod_mul(T a, T b, T m) {
	return mod_norm(a, m) * mod_norm(b, m) % m;
}

T mod_div(T a, T b, T m) {
	a = mod_norm(a, m);
	b = mod_norm(b, m);
	T x, y;
	T g = gcd_ext(b, m, &x, &y);
	T d = (g!=1) ? 0 : mod_norm(x, m);
	return (a * d) % m;
}

//this method can avoid integer overflow
T mod_combinations(int n, int k, T m) {
    if (k*2 > n) k = n-k;
    if (n==0) return 0;
    T r = 1; //C(n,0)
    for (int i=1; i<=k; i++) {
        //C(n,i) = C(n,i-1) * (n-i+1) / i
        r = mod_div(r * (n-i+1), i, m);
    }
    return r;
}


int h,w,a,b;

int input() {
	if (scanf("%d %d %d %d", &h, &w, &a, &b) < 0) return 0;
	return 1;
}

void init() {
}

int solve() {
	T r = mod_combinations(h+w-2, h-1, M);
	T x = mod_combinations(h-a+b-1, b-1, M);
	T y = mod_combinations(a-1+w-b-1, w-b-1, M);
	for (int i=0; i<a; i++) {
		//T x = mod_combinations(h-a+i+b-1, b-1, M);
		//T y = mod_combinations(a-1-i+w-b-1, w-b-1, M);
		if (i) {
			T n = h-a+i+b-1, m = b-1;
			x = mod_div(x*n, n-m, M);

			n = a-1-i+w-b-1, m = w-b-1;
			y = mod_div(y*(n+1-m), n+1, M);
		}
		T z = mod_mul(x, y, M);
		//printf("%d: r=%ld %ld %ld %ld\n", i, r, x, y, z);
		r = mod_sub(r, z, M);
		
	}
	return r;
}

void output(int ans) {
	printf("%d\n", ans);
}

void cleanup() {
}

int main() {
	//precalc();
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}


