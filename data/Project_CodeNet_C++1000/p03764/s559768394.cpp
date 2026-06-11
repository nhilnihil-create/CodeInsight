//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define M 1000000007
#define MAXN 100000

int m, n;
long a[MAXN], b[MAXN]; 

int input() {
	if (scanf("%d %d", &m, &n) < 0) return 0;
	for (int i=0; i<m; i++) scanf("%ld", &a[i]);
	for (int i=0; i<n; i++) scanf("%ld", &b[i]);
	return 1;
}

void init() {
}

long calc(long *a, int n) {
	n--;
	for (int i=0; i<n; i++)
		a[i] = a[i+1]-a[i];
	long s = 0, r = 0;
	for (int i=0; i<n; i++) {
		s += a[i] * (i+1);
		r += s;
		s %= M;
		r %= M;
	}
	return r;
}

long solve() {
	return calc(a, m) * calc(b, n) % M;
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
}

int main() {
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



