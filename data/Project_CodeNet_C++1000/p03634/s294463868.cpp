#include <iostream>
#include <string>
#include <algorithm>
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
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main() {
	int n;
	cin >> n;
	int q, k;
	vector < vector<pair<int, long long>>> vec(n + 10);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		vec[a].emplace_back(make_pair(b, c));
		vec[b].emplace_back(make_pair(a, c));
	}
	priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> que;
	long long co[100010];
	for (int i = 0; i < 100010; i++) {
		co[i] = 10000000000000007;
	}
	cin >> q >> k;
	que.push(make_pair(0, k));
	while (!que.empty()) {
		long long y = que.top().first;
		int x = que.top().second;
		que.pop();
		for (int i = 0; i < vec[x].size(); i++) {
			if (y + vec[x][i].second < co[vec[x][i].first]) {
				co[vec[x][i].first] = y + vec[x][i].second;
				que.push(make_pair(y + vec[x][i].second, vec[x][i].first));
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << co[l] + co[r] << endl;
	}
	return 0;
}
