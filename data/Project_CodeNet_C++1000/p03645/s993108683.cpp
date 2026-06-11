#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(200020);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].emplace_back(b);
		vec[b].emplace_back(a);
	}
	for (int i = 0; i < vec[1].size(); i++) {
		for (int j = 0; j < vec[vec[1][i]].size(); j++) {
			if (vec[vec[1][i]][j] == n) {
				cout << "POSSIBLE" << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}