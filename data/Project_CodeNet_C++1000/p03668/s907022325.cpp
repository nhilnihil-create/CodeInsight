#include <bits/stdc++.h>
 
using namespace std;
 
int n, ta, tb;
vector< int > x[100005];
 
int dfs(int a, int b) {
	int re = 0;
	for (int i = 0; i < x[a].size(); i++)
		if (x[a][i] != b)
			re ^= dfs(x[a][i], a) + 1;
	return re;
}
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &ta, &tb);
		x[ta].push_back(tb);
		x[tb].push_back(ta);
	}
	printf(dfs(1, 0) ? "Alice\n" : "Bob\n");
	return 0;
}