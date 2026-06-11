
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> g(n);
	for (int i = 0; i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].emplace_back(make_pair(c, b));
		g[b].emplace_back(make_pair(c, a));
	}

	vector<vector<int>>d(n, vector<int>(n, BIG_INT));

	for (int i = 0; i < n;i++) {
		priority_queue<pii, vector<pii>, greater<pii>>pq;
		d[i][i] = 0;
		pq.push(make_pair(0, i));
		
		vector<bool> isChecked(n, false);
		while (!pq.empty()) {
			int v = pq.top().second;
			pq.pop();
			if (!isChecked[v]) {
				for (pii e:g[v]) {
					if (d[i][v] + e.first < d[i][e.second]) {
						d[i][e.second] = d[i][v] + e.first;
						pq.push(make_pair(d[i][e.second], e.second));
					}
				}

				isChecked[v] = true;
			}
		}
	}
	/*
	for (int i = 0; i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	*/

	int cnt = 0;
	for (int i = 0; i < n;i++) {
		for (pii e : g[i]) {
			if (d[i][e.second] != e.first) {
				cnt++;
			}
		}
	}
	cout << cnt/2 << endl;
}
