#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k, x, y; scanf("%d %d %d %d", &n, &k, &x, &y);

	if (n <= k) printf("%d", x * n);
	else {

		int cost = k * x;

		printf("%d", cost + (n - k) * y);

	}

	return 0;

}