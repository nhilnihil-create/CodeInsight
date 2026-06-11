#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, long long>>> v(100000);
vector<long long> dist(100000);

void dfs(int i, int p, long long d);

int main()
{
	int n;
	cin >> n;

	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		a--;
		b--;

		v[a].emplace_back(make_pair(b, c));
		v[b].emplace_back(make_pair(a, c));
	}

	int q, k;
	cin >> q >> k;
	k--;
	dfs(k, k, 0);

	int x, y;
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		cout << dist[x - 1] + dist[y - 1] << endl;
	}
	
	return 0;
}

void dfs(int i, int p, long long d)
{
	dist[i] = d;

	for (auto & j : v[i]) {
		if (j.first == p) {
			continue;
		}

		dfs(j.first, i, d + j.second);
	}
}