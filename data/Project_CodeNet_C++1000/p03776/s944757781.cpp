#include <iostream>
#include <algorithm>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


ll com[53][53] = {};

int main(void) {
	int n, a, b, i, j, k1, k2, lim;
	ll v[53], dv[53], pt;
	double amax;

	scanf("%d%d%d", &n, &a, &b);
	for (i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
		dv[i] = v[i];
	}

	sort(v, v + n, greater<ll>());
	sort(dv, dv + n);

	amax = 0.0;
	for (i = 0; i < a; i++) {
		amax += v[i];
	}

	printf("%.12lf\n", amax / a);

	for (i = 0; i <= n; i++) for (j = 0; j <= i; j++) {
		if (j == 0 || j == i) {
			com[i][j] = 1;
		}
		else {
			com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
		}
	}

	k1 = dv + n - upper_bound(dv, dv + n, v[a - 1]);
	k2 = dv + n - lower_bound(dv, dv + n, v[a - 1]);

	lim = min(b, k2);

	if (amax / a > (double)v[a - 1]) {
		pt = com[k2 - k1][a - k1];
	}
	else {
		pt = 0;
		for (i = a - k1; i <= lim - k1; i++) {
			pt += com[k2 - k1][i];
		}
	}

	printf("%lld\n", pt);

	return 0;
}