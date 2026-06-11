#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

int n, m, a[maxn], pos[maxn];

int main()
{
	n = gi(); m = gi();
	int cnt = 0;
	pos[0] = 1; pos[1] = m;
	for (int i = 1; i <= m; ++i) {
		a[i] = gi();
		if (a[i] & 1) {
			if (cnt == 2) return puts("Impossible"), 0;
			pos[cnt++] = i;
		}
	}
	swap(a[1], a[pos[0]]);
	swap(a[m], a[pos[1]]);
	if (m == 1 && a[1] == 1) return puts("1\n1\n1"), 0;
	for (int i = 1; i <= m; ++i) printf("%d ", a[i]);
	if (m == 1) return printf("\n2\n1 %d\n", n - 1), 0;
	printf("\n%d\n%d ", a[m] > 1 ? m : m - 1, a[1] + 1);
	for (int i = 2; i < m; ++i) printf("%d ", a[i]);
	if (a[m] > 1) printf("%d\n", a[m] - 1);
	
	return 0;
}

