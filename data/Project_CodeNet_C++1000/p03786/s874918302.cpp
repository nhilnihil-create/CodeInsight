#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	long long a[n];
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) a[i + 1] += a[i];
	int k = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] * 3 < a[i + 1]) k = i + 1;
	printf("%d\n", n - k);
	return 0;
}