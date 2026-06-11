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
	int n, x;
	cin >> n >> x;

	if (x == 1 || x == 2 * n -1) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	deque<int> ans;
	ans.push_back(x);
	for (int i = 1; i < min(x,n); i++) {
		ans.push_front(i);
		
	}

	for (int i = 2 *n-1; i > max(x, n); i--) {
		ans.push_back(i);

	}

	if (x < n) {
		for (int i = x + 1; i <= n; i++) {
			ans.push_front(i);
		}
	}

	if (x > n) {
		for (int i = n; i <= x -1; i++) {
			ans.push_back(i);
		}
	}

	while (!ans.empty()) {
		cout << ans.front()<< " " << endl;
		ans.pop_front();
	}

}