#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main(void) {
	vector<long long> f;
	long long f1;
	long long a[110000];
	long long b[110000];
	vector<long long> p, pp, q, qq;
	long long c, d;
	long long k;
	long long l;
	long long n, m;
	long long s, t;
	long long x, y;
	long long le, ri, mi;
	long long np, nq;
	long long z;
	long long f0;
	long long start;
	scanf("%lld %lld %lld", &n, &l, &t);

	x = 0;
	y = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
		f1 = a[i] - (((b[i] * 2) - 3)*t);
		if (f1 < 0) {
			f1 = (-f1) % l;
			f1 = (l - f1) % l;
		}
		else f1 = f1 % l;
		if (i == 0)f0 = f1;
		f.push_back(f1);
		if (b[i] == b[0]) {
			pp.push_back(i);
		}
		else {
			qq.push_back(i);
		}
	}
	sort(f.begin(), f.end());
	if (b[0] == 1) {
		z = 0;
		for (int i = 0; i < qq.size(); i++) {
			x = a[qq[i]];
			x -= a[0];
			x = (x + l) % l;
			y = (l - x + (2 * t) - 1) / l;
			z = (z + y) % n;
		}
		for (int i = 0; i < f.size();i++) {
			if (f[i] == f0) {
				x = i - z;
				x = (x + n) % n;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			y = (x + i) % n;
			printf("%d\n", f[y]);
		}
	}
	else {
		z = 0;
		for (int i = 0; i < qq.size(); i++) {
			x = a[0];
			x -= a[qq[i]];
			x = (x + l) % l;
			y = (l - x + (2 * t) - 1) / l;
			y = y % n;
			y = (n - y) % n;
			z = (z + y) % n;
		}
		for (int i = f.size() - 1; i >= 0; i--) {
			if (f[i] == f0) {
				x = i - z;
				x = (x + n) % n;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			y = (x + i) % n;
			printf("%d\n", f[y]);
		}
	}
	return 0;

}