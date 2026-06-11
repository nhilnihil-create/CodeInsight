#include "bits/stdc++.h"
using namespace std;
int n, m;
vector <int> g[100010];
int col[100010];
long long isolate, bipartite, normal;
bool good;

void dfs(int x) {
	for(auto i : g[x]) {
		if(col[i] == -1) {
			col[i] = col[x] ^ 1;
			dfs(i); 
		} else if (col[i] == col[x]) {
			good = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].push_back(q);
		g[q].push_back(p);
	}
	memset(col, -1, sizeof col);
	for(int i = 1; i <= n; i++) {
		if(col[i] == -1) {
			col[i] = 0;
			good = true;
			dfs(i);
			if(g[i].empty()) {
				++isolate;
			} else if (good) {
				++bipartite;
			} else {
				++normal;
			}
		}
	}
	// cout << isolate << " " << bipartite << " " << normal << endl;

	long long ans = 0;
	ans += normal;
	ans += 2 * bipartite; 
	ans += (normal * (normal - 1));
	ans += 2 * bipartite * (bipartite - 1);
	ans += 2 * normal * bipartite;
	ans += 2 * isolate * (n - isolate);
	ans += isolate * isolate;

	printf("%lld\n", ans);
	return 0;
}