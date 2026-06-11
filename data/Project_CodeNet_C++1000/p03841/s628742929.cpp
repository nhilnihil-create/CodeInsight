#include <bits/stdc++.h>
using namespace std;
const int N = 500 * 500 + 5;
int n, x[N], c[N], id[N], a[N];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &x[i]), id[i] = i;
	sort(id + 1, id + n + 1, [](int a, int b) { return  x[a] < x[b]; });
	for(int i = 1, p = 1; i <= n; ++i) {
		for(int j = p; j < x[id[i]] && c[id[i]] < id[i] - 1; ++j, p = j)
			if (!a[p]) a[p] = id[i], c[id[i]]++;
		if (id[i] - 1 == c[id[i]] && x[id[i]] >= p) a[x[id[i]]] = id[i];
	}
	int flag = true;
	for(int i = 1; i <= n; ++i) flag &= a[x[i]] == i, flag &= c[i] == i - 1;
	if (!flag) { printf ("No\n"); return 0; }
	for(int i = n, p = n * n; i >= 1; --i) for(int j = p; j > x[id[i]] && c[id[i]] < n - 1; --j, p = j) {
		if (!a[p]) a[p] = id[i], c[id[i]]++;
	}
	flag = true;
	for(int i = 1; i <= n; ++i) flag &= c[i] == n - 1;
	if (!flag) { printf ("No\n"); return 0; }
	printf("Yes\n");
	for(int j = 1; j <= n * n; ++j) printf("%d%c", a[j], " \n"[j == n * n]);
	return 0;
}