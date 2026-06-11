#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, a[N], b[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; ++i) if(a[i] == a[i - 1]) b[++cnt] = a[i];
	n -= cnt;
	if(cnt & 1) --n;
	printf("%d\n", n);
	return 0;
}