#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define dprintf printf

int main() {
	LL a[3];
	scanf("%lld %lld %lld", &a[0], &a[1], &a[2]);

	for (int i = 0; i < 3; ++i) {
		if (a[i] % 2 == 0) {
			printf("0\n");
			return 0;
		}
	}
	LL d[3];
	d[0] = a[2] * a[1];
	d[1] = a[0] * a[2];
	d[2] = a[0] * a[1];
	printf("%lld\n", min(d[0], min(d[1], d[2])));
}