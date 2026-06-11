#include <bits/stdc++.h>
using namespace std;

long long x, y;

signed main () {
	scanf("%lld %lld", &x, &y);
	if (abs(x - y) > 1)
		printf("Alice\n");
	else
		printf("Brown\n");
}
