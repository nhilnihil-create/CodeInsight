#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, m, q;
vector <int> ad[N];
int str[N], clr[N], dis[N];
int res[N], cld[N];

void solve(int t) {
	if (dis[t] == 0 && !res[str[t]])
		res[str[t]] = clr[t];
	if (cld[str[t]] >= dis[t])
		return;
	cld[str[t]] = dis[t]; 
	queue < pair <int, int> > qer;
	qer.push({str[t], dis[t]});
	if (!res[str[t]])
		res[str[t]] = clr[t];
	while (qer.size()) {
		int v = qer.front().first, d = qer.front().second;
		qer.pop();
		if (!d)
			continue;
		for (auto u: ad[v]) {
			if (cld[u] < d - 1) {
				qer.push({u, d - 1});
				cld[u] = d - 1;
				if (!res[u])
					res[u] = clr[t];
			}
			if (!res[u])
				res[u] = clr[t];	
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		ad[a].push_back(b);
		ad[b].push_back(a);
	}
	cin >> q;
	for (int i = 1; i <= q; i++)
		cin >> str[i] >> dis[i] >> clr[i];
	for (int i = q; i >= 1; i--)
		solve(i);
	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;
	return 0;
}
