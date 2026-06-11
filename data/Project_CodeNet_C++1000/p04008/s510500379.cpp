#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, x, ret; vector<int> g[100009];
int solve(int pos) {
	int mx = 0;
	for (int i : g[pos]) {
		int res = solve(i);
		if (res == K - 1) ret++;
		else mx = max(mx, res + 1);
	}
	return mx;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> x; x--;
		if (i >= 1) {
			g[x].push_back(i);
		}
		else if (x != 0) ret++;
	}
	for (int i : g[0]) {
		solve(i);
	}
	cout << ret << "\n";
	return 0;
}