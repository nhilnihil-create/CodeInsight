#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double EPS = 1e-10;
vector<int> G[100000];
int dfs(int v) {
	priority_queue<int, vector<int>, greater<int>> Q;
	int k = 0;
	for (int to : G[v]) {
		Q.push(dfs(to));
		k++;
	}
	if (k == 0) return 0;
	if (k == 1) return Q.top() + 1;
	int ret = 0;
	Q.push(0);
	int m1 = Q.top(); Q.pop();
	int m2 = Q.top(); Q.pop();
	ret = max(ret, m1 + k);
	ret = max(ret, m2 + k);
	for (int i = k - 1; i > 0; i--) {
		int m = Q.top(); Q.pop();
		ret = max(ret, m + i);
	}
	return ret;
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		a--;
		G[a].push_back(i);
	}
	cout << dfs(0) << endl;
}