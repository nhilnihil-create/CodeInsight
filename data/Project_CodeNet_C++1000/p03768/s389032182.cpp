#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD 1000000007

#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct Node {
	int color = 0;
	int lock = -1;
	vector<int> nexts;
};

struct Query {
	int v, d, c;
	Query(int v, int d, int c) : v(v), d(d), c(c) {}
};

vector<Node> nodes;

void print(int now, int dist, int color) {
	if (nodes[now].lock >= dist) return;
	nodes[now].lock = dist;
	if (nodes[now].color == 0) nodes[now].color = color;

	if (dist == 0) return;
	for (int next : nodes[now].nexts) {
		print(next, dist - 1, color);
	}
}

signed main() {
	int N, M;
	cin >> N >> M;

	nodes.resize(N);

	rep(i, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		nodes[a].nexts.push_back(b);
		nodes[b].nexts.push_back(a);
	}

	int Q;
	cin >> Q;
	vector<Query> queries;
	rep(i, Q) {
		int v, d, c;
		cin >> v >> d >> c;
		v--;
		queries.push_back(Query(v, d, c));
	}

	reverse(all(queries));

	for (auto &query : queries) {
		print(query.v, query.d, query.c);
	}

	for (auto &node : nodes) { 
		cout << node.color << endl;
	}
}
