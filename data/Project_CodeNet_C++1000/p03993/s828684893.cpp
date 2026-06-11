#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[a[i]] == i && i < a[i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}