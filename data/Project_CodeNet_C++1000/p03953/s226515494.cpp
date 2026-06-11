#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 10;

int n, m, a[N], p[N], vis[N];
vector<int> vec;
LL x[N], k, d[N], res[N];

void dfs(int x) {
	vis[x] = 1;
	vec.push_back(x);
	if (!vis[p[x]]) dfs(p[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &x[i]);
	}
	for (int i = 1; i < n; ++i)
		d[i] = x[i + 1] - x[i];
	scanf("%d%lld", &m, &k);
	for (int i = 1; i < n; ++i)
		p[i] = i;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
		swap(p[a[i] - 1], p[a[i]]);
	}
	for (int i = 1; i < n; ++i) {
		if (vis[i]) continue;
		vec.clear();
		dfs(i);
		int siz = vec.size();
		int del = k % siz;
		for (int j = 0; j < vec.size(); ++j) 
			res[vec[j]] = d[vec[(j + del) % siz]];
	}
	LL ans = x[1];
	printf("%lld\n", ans);
	for (int i = 1; i < n; ++i) {
		ans += res[i];
		printf("%lld\n", ans);
	}
	return 0;
}
