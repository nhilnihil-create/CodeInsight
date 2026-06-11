#include <bits/stdc++.h>

const int N = 540, N2 = 254000;

int n, n2;
int pos[N], a[N2];
int o[N], remain[N];

int main() {
	int i, j;
	scanf("%d", &n), n2 = n * n;
	for (i = 1; i <= n; ++i) scanf("%d", pos + i), a[pos[i]] = i, o[i - 1] = i;
	std::sort(o, o + n, [] (const int x, const int y) {return pos[x] < pos[y];});
	for (i = 1; i <= n; ++i) remain[i] = i - 1;
	j = !remain[*o];
	for (i = 1; i <= n2 && j < n; ++i)
		if (!a[i]) for (--remain[ a[i] = o[j] ]; j < n && !remain[o[j]]; ++j);
		else if (remain[a[i]]) break;
	if (j < n) return puts("No"), 0;
	for (i = 1; i <= n; ++i) remain[i] = n - i;
	j = (remain[o[n - 1]] ? n - 1 : n - 2);
	for (i = n2; i && j >= 0; --i)
		if (!a[i]) for (--remain[ a[i] = o[j] ]; j >= 0 && !remain[o[j]]; --j);
		else if (remain[a[i]]) break;
	if (j >= 0) return puts("No"), 0;
	puts("Yes");
	for (i = 1; i <= n2; ++i) printf("%d%c", a[i], i == n2 ? 10 : 32);
	return 0;
}