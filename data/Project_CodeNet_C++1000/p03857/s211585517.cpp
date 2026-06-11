# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <unordered_map>
constexpr int MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
using namespace std;
using LL = long long;

int Par[1200001];
int Rank[1200001];

void init(int n) {
	for (int i = 0; i < n; i++) {
		Par[i] = i;
		Rank[i] = 0;
	}
}

int find(int x) {
	if (Par[x] == x) {
		return x;
	}
	else {
		return Par[x] = find(Par[x]);
	}
}

void unite(int  x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (Rank[x] < Rank[y]) {
		Par[x] = y;
	}
	else {
		Par[y] = x;
		if (Rank[x] == Rank[y])Rank[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int n, k, l;
	cin >> n >> k >> l;
	init(n * 2 + 2);
	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		unite(a, b);
	}
	for (int i = 0; i < l; i++) {
		cin >> a >> b;
		unite(n + a, n + b);
	}
	pair<int, int> p[1200001];
	map<pair<int, int>, int> m;
	for (int i = 1; i <= n; i++) {
		p[i] = make_pair(find(i), find(i + n));
	}
	for (int i = 1; i <= n; i++) {
		m[p[i]] ++;
	}
	for (int i = 1; i <= n; i++) {
		if(i!=n)cout << m[p[i]] << " ";
		else cout << m[p[i]] << endl;
	}
}