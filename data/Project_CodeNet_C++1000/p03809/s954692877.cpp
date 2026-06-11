#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, a[100009]; vector<int> g[100009];
long long calc(int pos, int pre) {
	if (g[pos].size() == 1) return a[pos];
	long long mx = 0, sum = 0;
	for (int i : g[pos]) {
		if (i == pre) continue;
		long long res = calc(i, pos);
		if (res == -1) return -1;
		sum += res;
		mx = max(mx, res);
	}
	long long ops = sum - a[pos];
	long long lim = min(sum - mx, sum / 2);
	if (ops < 0 || ops > lim) return -1;
	return sum - ops * 2;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y; x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int root = 0;
	for (int i = 1; i < N; i++) {
		if (g[i].size() >= 2) root = i;
	}
	long long ret = calc(root, -1);
	cout << ((N == 2 && a[0] == a[1]) || (N >= 3 && ret == 0) ? "YES\n" : "NO\n");
	return 0;
}