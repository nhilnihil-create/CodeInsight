#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int a[1999], b[1999];
vector<int> et[2000];

int dfs(int p, int v, int remDep) {
	int i;
	
	if (remDep == 0) {
		return 1;
	}
	
	int ret = 1;
	for (i = 0; i < et[v].size(); i++) {
		int nv = et[v][i];
		if (nv == p) continue;
		int res = dfs(v, nv, remDep - 1);
		ret += res;
	}
	return ret;
}

int main() {
	int i;
	
	cin >> n >> k;
	for (i = 0; i < n - 1; i++) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		et[a[i]].push_back(b[i]);
		et[b[i]].push_back(a[i]);
	}
	
	int maxV = 0;
	for (i = 0; i < n; i++) {
		int res = dfs(-1, i, k / 2);
		maxV = max(maxV, res);
	}
	
	for (i = 0; i < n - 1; i++) {
		int res1 = dfs(a[i], b[i], (k - 1) / 2);
		int res2 = dfs(b[i], a[i], (k - 1) / 2);
		maxV = max(maxV, res1 + res2);
	}
	cout << n - maxV << endl;
	return 0;
}