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
	bool visited = false;
	vector<int> nexts;
};

vector<Node> nodes;

void dfs(int now, deque<int> &ret, bool front) {
	nodes[now].visited = true;

	if (front) ret.push_front(now);
	else ret.push_back(now);

	for (int next : nodes[now].nexts) {
		if (nodes[next].visited) continue;
		dfs(next, ret, front);
		break;
	}
}

signed main() {
	int N, M;
	cin >> N >> M;

	nodes.resize(N);

	rep(i, M) {
		int A, B;
		cin >> A >> B;
		A--; B--;
		nodes[A].nexts.push_back(B);
		nodes[B].nexts.push_back(A);
	}

	deque<int> ret;
	dfs(0, ret, true);
	ret.pop_back();
	dfs(0, ret, false);

	cout << ret.size() << endl;
	for (int num : ret) cout << num + 1 << " ";
	cout << endl;
}
