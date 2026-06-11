#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main() {
	int n, m;
	cin >> n >> m;
	int graph[100][100] = {};
	int unused[100][100] = {};
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		graph[a][b] = c;
		graph[b][a] = c;
		unused[a][b] = 1;
		unused[b][a] = 1;
	}
	priority_queue<pair<int, pair<int, int> > > qu;
	for (int i = 0; i < n; i++) {
		// cout << i << endl;
		vector<int> minCost(n, MOD);
		qu.push(make_pair(0, make_pair(i, i)));
		while (!qu.empty()) {
			int prev = ((qu.top()).second).first;
			int now = ((qu.top()).second).second;
			int cost = -(qu.top()).first;
			qu.pop();
			if (cost > minCost[now]) continue;
			if (cost == minCost[now]) {
				unused[prev][now] = 0;
				unused[now][prev] = 0;
				continue;
			}
			// cout << "\t" << now << " " << cost << endl;
			minCost[now] = cost;
			unused[prev][now] = 0;
			unused[now][prev] = 0;
			for (int j = 0; j < n; j++) {
				if (graph[now][j] == 0) continue;
				int nextcost = cost + graph[now][j];
				if (nextcost < minCost[j]) {
					// cout << "\t\t" << j << endl;
					qu.push(make_pair(-nextcost, make_pair(now, j)));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += unused[i][j];
		}
	}
	cout << ans / 2 << endl;
}