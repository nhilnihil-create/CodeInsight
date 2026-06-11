#include<cstdio>
#include<vector>
using namespace std;

int n, x, y;
vector<int> g[100100];

int Dfs(int x, int fa) {
	int ans = 0;
	for(int i = 0; i < (int)g[x].size(); i++) {
		int v = g[x][i];
		if(v == fa) continue;
		ans ^= (Dfs(v, x) + 1);
	}
//	printf("%d : %d\n", x, ans ^ c1);
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	Dfs(1, 0) ? puts("Alice") : puts("Bob");
}