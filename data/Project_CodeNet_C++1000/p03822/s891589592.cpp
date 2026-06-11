#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
const double EPS = 1e-7;
const double MAX = 1000 + 5;


int main() {
	int n;
	cin >> n;
	vector<vector<int>> t(n);
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		a--;
		t[a].emplace_back(i);
	}

	stack<int> s;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : t[v]) {
			q.push(u);

		}
		s.push(v);
	}

	vector<int> d(n);
	while (!s.empty()) {
		vector<int> dp;
		int v = s.top();
		s.pop();
		for (int u : t[v]) {
			dp.emplace_back(d[u]);
		}

		sort(dp.begin(), dp.end(), greater<int>());
		int l = dp.size();
		for (int i = 0; i < l; i++) {

			dp[i] += i + 1;
		}

		sort(dp.begin(), dp.end(), greater<int>());

		if (l > 0) {
			d[v] = dp[0];
		}
		else {
			d[v] = 0;
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	*/
	cout << d[0] << endl;
}