#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 10;
vector<int> Mat[MAXN];
int n, k, ans;

int dfs(int v, int p) {
	int t = 1;
	for (int i = 0; i < Mat[v].size(); i++)
		t = max(t, dfs(Mat[v][i], v) + 1);
	if (t == k && p != 1) {
		ans++;
		return 0;
	}
	return t;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		ans += (i == 1 && a != 1);
		if (i != 1)
			Mat[a].push_back(i);
	}
	dfs(1, 1);
	cout << ans;
}