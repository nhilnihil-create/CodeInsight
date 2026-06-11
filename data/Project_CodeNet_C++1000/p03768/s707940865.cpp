#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

vector<vector<ll>> T(100000);
queue<vector<ll>> ue;

int main() {
	int N, M;
	cin >> N >> M;
	ll a, b, c;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		a--;b--;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	cin >> M;
	vector<int> color(M);
	vector<vector<pair<ll, ll>>> query(11);
	vector<vector<ll>> ans(11, vector<ll>(N, -1));
	for (int i = 0;i < M;i++) {
		cin >> a >> b >> c;
		a--;
		color[i] = c;
		query[b].push_back({ i,a });
	}
	for (int k = 0;k < 11;k++) {
		int ss = query[k].size();
		sort(all(query[k]));
		for (int j = ss - 1;j >= 0;j--) {
			b = query[k][j].first;
			a = query[k][j].second;
			if (ans[k][a] < b)
				ue.push({ a,b,k });
		}
		while (!ue.empty()) {
			a = ue.front()[0];
			b = ue.front()[1];
			if (ans[k][a] < b) {
				ans[k][a] = b;
				c = ue.front()[2];
				if (c) {
					int saz = T[a].size();
					for (int i = 0;i < saz;i++)
						ue.push({ T[a][i],b,c - 1 });
				}
			}
			ue.pop();
		}
	}
	for (int i = 0;i < N;i++) {
		c = ans[0][i];
		for (int j = 1;j < 11;j++)
			c = max(ans[j][i], c);
		if (c == -1)
			cout << 0 << endl;
		else
			cout << color[c] << endl;
	}
}