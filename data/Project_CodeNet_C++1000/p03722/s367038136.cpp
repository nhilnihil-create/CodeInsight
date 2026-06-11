
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
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].emplace_back(make_pair(b, -c));
	}

	vector<ll> d(n, BIG_NUM);
	d[0] = 0;
	bool isInf = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++) {
			if (d[j] != BIG_NUM) {
				for (pii e : g[j]) {
					if (d[e.first] > d[j] + e.second) {
						d[e.first] = d[j] + e.second;
						if (i == n - 1 && (e.first == n-1 || j == n-1)) {
							isInf = true;
						}

					}
				}
			}
		}
	}
	if (isInf) {
		cout << "inf"<< endl;
	}
	else {
		cout << -d[n - 1] << endl;
	}
}



