#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 55
using namespace std;

typedef long long ll;
ll n, a, b, s, c1, c2, ans, v[N], c[N][N];
int main()
{
	ll i, j;
	cin >> n >> a >> b;
	for (i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	for (i = 0; i < n; i++) scanf("%lld", &v[i]);
	sort(v, v + n, greater<ll>());
	for (i = 0; i < a; i++) s += v[i];
	for (; i < n; i++) {
		if (v[i] == v[a - 1]) c1++;
		else break;
	}
	for (i = a - 1; i >= 0; i--) {
		if (v[i] == v[a - 1]) c1++, c2++;
		else break;
	}
	if (v[0] != v[a - 1]) {
		printf("%.9f\n%lld", 1.0 * s / a, c[c1][c2]);
	} else {
		for (i = a; i <= b; i++) ans += c[c1][i];
		printf("%.9f\n%lld", 1.0 * s / a, ans);
	}
    return 0;
}