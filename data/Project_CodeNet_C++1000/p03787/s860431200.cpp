#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N, M;
vector <int> E[MAXN];
int color[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
}

bool dfs(int x, int c) {
	if (color[x] != -1)
		return color[x] == c;
	color[x] = c;
	bool ans = true;
	for (auto it : E[x])
		ans &= dfs(it, c ^ 1);
	return ans;
}

ll square(int x) {
	return (ll)x * x;
}

ll solve() {
	memset(color, -1, sizeof color);	
	int cnt[2] = {0}, iso = 0;
	for (int i = 1; i <= N; i++)
		if (E[i].empty())
			iso++;
		else if (color[i] == -1)
			cnt[dfs(i, 0)]++;
	
	return (ll)iso * (2 * N - iso) + square(cnt[0] + cnt[1]) + square(cnt[1]);
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}