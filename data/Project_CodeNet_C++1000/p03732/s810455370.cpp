#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <numeric>
#include <functional>
#include <array>
#include <map>
#include <set>

#define INF 1000000007 //1000000000000000003
#define MOD 1000000007

#define ll long long

using namespace std;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using edge = struct { int to; long long dist; };

vector<edge>tree[100010];
vector<P> connect[100005];
long long cost[100005];

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {

	int N, W;
	cin >> N >> W;

	vector<int> v0[4];
	ll w1 = 0;
	for (int i = 0; i < N;++i) {
		int w, v;
		cin >> w >> v;
		if (i == 0)w1 = w;
		w -= w1;
		v0[w].emplace_back(v);
	}

	for (int i = 0; i < 4;++i) {
		sort(v0[i].begin(), v0[i].end());
		v0[i].emplace_back(0);
		reverse(v0[i].begin(), v0[i].end());
		for (int j = 1; j < v0[i].size();++j) {
			v0[i][j] += v0[i][j - 1];
		}
	}

	int ans = 0;
	for (ll i = 0; i < v0[0].size();++i ) {
		for (ll j = 0; j < v0[1].size(); ++j) {
			for (ll k = 0; k < v0[2].size(); ++k) {
				for (ll l = 0; l < v0[3].size(); ++l) {
					if((w1 * i + (w1 + 1) * j + (w1 + 2) * k + (w1 + 3) * l) <= W){
						ans = max(ans, (v0[0][i] + v0[1][j] + v0[2][k] + v0[3][l]));
					}
				}
			}
		}
	}
	cout << ans << endl;
}