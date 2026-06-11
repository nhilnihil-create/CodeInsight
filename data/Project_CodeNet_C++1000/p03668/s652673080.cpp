#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 6;

int f[maxn];
vector<int> E[maxn];

void dfs(int x,int pi) {
	f[x] = 0;
	for (int i = 0; i < E[x].size(); i++) {
		int z = E[x][i];
		if (z == pi) continue;
		dfs(z,x);
		f[x] ^= 1 + f[z];
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i < n; i++) {
		int x,y; scanf("%d %d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1,-1);
	printf(f[1]==0 ? "Bob\n" : "Alice\n");
}

