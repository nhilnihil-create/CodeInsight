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

const int N = 2e5 + 7;
const int ALP = 26;
const int INF = 1e9 + 239;

vector<int> pos[ALP];

int dp[N];
int wr[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = (int)s.size();
	s.push_back('?');
	n++;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			for (int j = 0; j < ALP; j++) {
				pos[j].push_back(i);
			}
		} else {
			pos[s[i] - 'a'].push_back(i);
		}
	}
	dp[n - 1] = 1;
	wr[n - 1] = -1;
	for (int i = n - 2; i >= 0; i--) {
		int mn = INF;
		int wmn = -1;
		for (int c = 0; c < ALP; c++) {
			int v = *upper_bound(pos[c].begin(), pos[c].end(), i);
			if (mn > dp[v] + 1) {
				mn = dp[v] + 1;
				wmn = c;
			}
		}
		dp[i] = mn;
		wr[i] = wmn;
	}
	int ans = INF;
	int fr = -1;
	for (int c = 0; c < ALP; c++) {
		if (ans > dp[pos[c].front()]) {
			ans = dp[pos[c].front()];
			fr = c;
		}
	}
	// cout << ans << endl;
	string res;
	res.push_back(fr + 'a');
	{
		int pnt = pos[fr].front();
		while (pnt + 1 < n) {
			res.push_back('a' + wr[pnt]);
			int v = *upper_bound(pos[wr[pnt]].begin(), pos[wr[pnt]].end(), pnt);
			pnt	= v;
		}
	}
	cout << res << endl;
}
