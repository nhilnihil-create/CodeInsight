#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;
int N;
int A[MAXN];
vector<int> adj[MAXN];
int ok = -1;

inline ll Dfs(int x, int fa = 0) {
	ll res = A[x];
	if(adj[x].size() > 1) res += A[x];
	for(auto v: adj[x])
		if(v != fa) {
			ll tmp = Dfs(v, x);
			if(tmp > A[x]) ok = 0;
			res -= tmp;
		}
	if(res < 0 || res > A[x]) ok = 0;
	return res;
}

int main() {
	register int i; int x, y;
	scanf("%d", &N);
	for(i = 1; i <= N; ++i)
		scanf("%d", A + i);
	for(i = 1; i < N; ++i)
		scanf("%d%d", &x, &y),
		adj[x].push_back(y),
		adj[y].push_back(x);
	int rt = 1;
	for(i = 2; i <= N; ++i) if(adj[i].size() > 1) rt = i;
	ok = !Dfs(rt) && (ok == -1);
	puts(ok ? "YES" : "NO");
	return 0;
}