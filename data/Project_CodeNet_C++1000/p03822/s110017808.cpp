#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1, 0), c(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		cin >> v[i];
		c[v[i]]++;
	}
	vector<int> res(n + 1, 0);
	vector<int> nodes;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			nodes.push_back(i);
		}
	}
	vector<vector<int>> children(n + 1, vector<int>(0));
	while (nodes.size() > 0) {
		int node = nodes.back();
		nodes.pop_back();
		if (children[node].size() == 0) {
			children[v[node]].push_back(0);
		} else {
			sort(children[node].begin(), children[node].end(), greater<int>());
			int min_res = 0;
			for (int i = 0; i < children[node].size(); i++) {
				min_res = max(min_res, children[node][i] + i + 1);
			}
			if (v[node] == 0) {
				cout << min_res  << endl;
				return 0;
			}
			children[v[node]].push_back(min_res);
		}
		c[v[node]]--;
		if (c[v[node]] == 0) {
			nodes.push_back(v[node]);
		}
	}

}




