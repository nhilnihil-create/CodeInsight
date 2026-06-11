#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

vector<int>V[2], ans, ret;

int n, sum;

int main () {
	scanf("%d%d", &sum, &n);
	for (int i = 1, j; i <= n; ++i) {
		scanf("%d", &j);
		V[j & 1].emplace_back(j);
	}
	if (V[1].size() > 2) return puts("Impossible"), 0;
	if (V[1].size()) ans.emplace_back(V[1][0]);
	for (auto v : V[0]) ans.emplace_back(v);
	if (V[1].size() > 1) ans.emplace_back(V[1][1]);
	int s = 0;
	for (auto v : ans) {
		printf("%d ", v);
		if (s + v - 1 > 0) ret.emplace_back(s + v - 1);
		s = 1;
	}
	if (n == 1) ret.push_back(1);
	else ++ret.back();
	putchar('\n');
	printf("%d\n", ret.size());
	for (auto v : ret) printf("%d ", v);
	return 0;
}
/*
16 7
3 2 2 2 2 2 3
*/