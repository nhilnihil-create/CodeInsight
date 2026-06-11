#include <bits/stdc++.h>

typedef long long ll;

const int kN = 1e5 + 5;

int a[kN], ans[kN], lptr, rptr; ll tot = 0;

int main() {
	int n; ll L;
	scanf("%d%lld", &n, &L);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i < n; ++i)
		if(a[i] + a[i + 1] >= L) {
			printf("Possible\n");
			for(int j = 1; j < i; ++j)
				printf("%d\n", j);
			for(int j = n - 1; j > i; --j)
				printf("%d\n", j);
			printf("%d\n", i);
			return 0;
		}
	printf("Impossible");
	return 0;
}