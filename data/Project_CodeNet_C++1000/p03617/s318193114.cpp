#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int q, h, s, d;
int n;

long long ans;

int main(){
	scanf("%d %d %d %d", &q, &h, &s, &d);
	scanf("%d", &n);
	h = min(h, 2 * q);
	s = min(s, 2 * h);
	d = min(d, 2 * s);
	ans = 1LL * (n / 2) * d + (n % 2) * s;
	printf("%lld\n", ans);
	return 0;
}