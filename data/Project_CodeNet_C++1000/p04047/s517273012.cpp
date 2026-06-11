#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[305];
	scanf("%d", &n); n <<= 1;
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	std::sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i += 2) ans += a[i];
	printf("%d", ans);
	return 0;
}
