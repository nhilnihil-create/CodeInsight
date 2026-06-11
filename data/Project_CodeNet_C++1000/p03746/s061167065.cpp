#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 1e5 + 7;

int used[N];
vector<int> g[N]; 

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
		
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	vector<int> ans = {0};
	used[0] = 1;
	while (true) {
		int v = ans.back();
		int any = 0;
		for (auto u : g[v]) {
			if (!used[u] && !any) {
				used[u] = 1;
				ans.push_back(u);
				any = 1;
				break;
			}
		}
		if (!any) {
			break;
		}
	}
	reverse(ans.begin(), ans.end());
	while (true) {
		int v = ans.back();
		int any = 0;
		for (auto u : g[v]) {
			if (!used[u] && !any) {
				used[u] = 1;
				ans.push_back(u);
				any = 1;
				break;
			}
		}
		if (!any) {
			break;
		}
	}
	cout << ans.size() << endl;
	for (auto t : ans) {
		cout << t + 1 << ' ';
	}
	cout << endl;
}