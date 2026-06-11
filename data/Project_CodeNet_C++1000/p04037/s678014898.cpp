#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	int x = n;
	for (int i = 1; i <= n; i++) {
		if (a[i] < i) {
			x = i - 1;
			break;
		}
	}
	int t1 = a[x] - x, t2 = 0;
	for (int i = x + 1; i <= n; i++)
		if (a[i] >= x)
			t2++;
	if (t1 % 2 == 0 && t2 % 2 == 0) puts("Second");
	else puts("First");
	return 0;
}