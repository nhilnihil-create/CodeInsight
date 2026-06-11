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

#define INF /*1000000007*/ 1000000000000000003
#define MOD 1000000007

using namespace std;
using P = pair<int, long long>;
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

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M;++i) {
		int a, b; long long c;
		cin >> a >> b; cin >> c;
		--a, --b;
		connect[a].push_back(make_pair(b, -c));
	}

	for (int i = 0; i < N;++i) {
		cost[i] = INF;
	}
	cost[0] = 0;
	
	bool isInf = false;
	for (int i = 0; i < N;++i) {
		for (int j = 0; j < N;++j) {
			for (P e : connect[j]) {
				if (cost[j] != INF && cost[j] + e.second < cost[e.first]) {
					cost[e.first] = cost[j] + e.second;
					if (i == N - 1 && e.first == N - 1)isInf = true;
				}
			}
		}
	}

	if (isInf)cout << "inf" << endl;
	else cout << -cost[N - 1] << endl;
}
