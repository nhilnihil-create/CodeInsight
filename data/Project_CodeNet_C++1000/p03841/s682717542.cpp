#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 505;
pii p[N];
int n, vis[N *  N];

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i].first), p[i].second = i;
	sort(p + 1, p + n + 1);
	for (int i = 1, j = 1, k; i <= n; ++i) {
		k = p[i].second;
		for (; k > 1 && j < p[i].first; ++j) if (!vis[j]) --k, vis[j] = p[i].second;
		if (k > 1) return puts("No"), 0;
		vis[p[i].first] = p[i].second;
	}
	for (int i = n, j = n * n, k; i; --i) {
		k = n - p[i].second;
		for (; k > 0 && j > p[i].first; --j) if (!vis[j]) --k, vis[j] = p[i].second;
		if (k > 0) return puts("No"), 0;
	}
	puts("Yes");
	for (int i = 1; i <= n * n; ++i) printf("%d ", vis[i]);
	return 0;
}