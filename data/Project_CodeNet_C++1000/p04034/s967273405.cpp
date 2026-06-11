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
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> num(n, 1);
	vector<bool> canR(n);
	canR[0] = true;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		num[x]--;
		num[y]++;
		if (canR[x]) {
			canR[y] = true;
		}

		if (num[x] == 0) {
			canR[x] = false;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (canR[i]) {
			cnt++;
		}
	}
	cout << cnt << endl;
}