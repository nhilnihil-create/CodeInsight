#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int n, a[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	int x = 0, y = 0;
	while (y+1 < a[x+1]) ++ x, ++ y;
	int len_u = a[x] - y;
	int len_r = 0; while (a[x + len_r] > y) ++ len_r;
	if ((!(len_r & 1)) || (!(len_u & 1))) puts("First");
	else puts("Second");
	return 0;
}