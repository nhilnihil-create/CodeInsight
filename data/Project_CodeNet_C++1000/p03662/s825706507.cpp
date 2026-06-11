#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int n;
struct node {
	vector<int> v;
};
node tree[123456];
bool b[123456]; vector<int>path;
bool p(int k) {
	for (int i = 0; i < tree[k].v.size(); i++) {
		int p1 = tree[k].v[i];
		if (p1 == n) {
			return 1;
		}
		else if (!b[p1]) {
			path.push_back(p1);
			b[p1] = 1;
			if (p(p1)) {
				return 1;
			}
			path.pop_back();
			b[p1] = 0;
		}
	}
	return 0;
}
int q(int k) {
	int r = 0;
	for (int i = 0; i < tree[k].v.size(); i++) {
		int p1 = tree[k].v[i];
		if (!b[p1]) {
			b[p1] = 1;
			r += q(p1);
		}
	}
	return r + 1;
}
signed main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		tree[a].v.push_back(b);
		tree[b].v.push_back(a);
	}
	b[1] = 1; b[n] = 1;
	path.push_back(1);
	p(1);
	path.push_back(n);
	int F = 0, S = 0;
	for (int i = 0; i < (path.size() + 1) / 2; i++) F += q(path[i]);
	for (int i = (path.size() + 1) / 2; i < path.size(); i++) S += q(path[i]);
	cout << (F > S ? "Fennec\n" : "Snuke\n");
}