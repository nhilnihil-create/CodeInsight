#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n, s, x, mn, a[200005];
int main() {
	int i;
	scanf("%lld", &n);
	for(i=0; i<n; i++) scanf("%lld", &a[i]), s += a[i];
	x = a[0];
	mn = abs(s-2*x);
	for(i=1; i<n-1; i++) {
		x += a[i];
		mn = min(mn, (long long)abs(s-2*x));
	}
	printf("%lld", mn);
	return 0;
}