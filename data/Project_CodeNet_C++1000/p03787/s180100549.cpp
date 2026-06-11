# include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

vector<int> g[maxn];
bool vis[maxn];
int dis[maxn];
int n, m;

int cnt;
bool odd;
void bfs(int s) {
	cnt = 0;
	odd = false;
	dis[s] = 0;
	vis[s] = true;
	queue<int> q; q.push(s);
	while(!q.empty()) {
		s = q.front(); q.pop();
		cnt += 1;
		for(auto x: g[s]) if(!vis[x]) {
			vis[x] = true;
			dis[x] = dis[s] + 1;
			q.push(x);
		} else if((dis[s] ^ dis[x] ^ 1) & 1) {
			odd = true;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	long long ans = 0;
	int bk0 = 0, bk1 = 0, bb = 0;
	for(int i = 1; i <= n; ++i) if(!vis[i]) {
		bfs(i);
		if(cnt == 1) {
			bb++;
		} else {
			odd ? bk1 ++ : bk0 ++ ;
		}
	}
	ans = 2ll * (n - bb) * bb + 1ll * bb * bb;
	ans += 2ll * bk0 * bk0;
	ans += 2ll * bk0 * bk1;
	ans += 1ll * bk1 * bk1;
	cout << ans << endl;
	return 0;
}
