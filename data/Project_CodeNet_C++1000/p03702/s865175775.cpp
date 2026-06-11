#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

long long n, a, b, val;
long long v[MAXN];

long long check (int md) {
	long long ret = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] - md * b > 0) {
			ret += (v[i] - md * b + a - 1) / a;
		}
	}
	return ret;
}

int main (void) {
	scanf("%lld%ld%lld", &n, &a, &b);
	a = a - b;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
	}
	int st = 1, en = 1e9, md;
	while (st != en) {
		md = (st + en) >> 1;
		if (check(md) <= md) en = md;
		else st = md + 1;
	}
	printf("%d\n", st);
}
