#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 2e5 + 5;
int color[MAX];
int n, m;
vector<int> adj[MAX];
bool visited[MAX];

int bfs(int source) {
	queue<int> q;
	q.push(source);
	visited[source] = true;
	int total = 0;
	bool bip = true;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		total++;
		for(auto &each : adj[cur]) {
			if(!visited[each]) {
				visited[each] = true;
				color[each] = !color[cur];
				q.push(each);
			}
			else if(color[cur] == color[each]) {
				bip = false;
			}
		}
	}
	return total == 1 ? 0 : (bip ? 1 : 2);
}

int main() {
	scanf("%d %d", &n, &m);
	fori(i, 0, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int isolated = 0, nbp = 0, bp = 0;
	fori(i, 1, n + 1) {
		if(!visited[i]) {
			int r = bfs(i);
			if(r == 0) {
				isolated++;
			}
			else if(r == 1) {
				bp++;
			}
			else {
				nbp++;
			}
		}
	}

	ll ans = 1LL * nbp * nbp + 2LL * nbp * bp + 2LL * bp * bp;
	int to_remove = 1;
	fori(i, 0, isolated) {
		ans += 2 * n - to_remove;
		to_remove += 2;
	}
	printf("%lld\n", ans);

	return 0;
}

