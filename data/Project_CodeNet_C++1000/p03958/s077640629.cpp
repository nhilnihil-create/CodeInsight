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
	int k, t;
	cin >> k >> t;
	vector<int> a(t);
	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end(),greater<int>());


	int ans = 2 * a[0] - k - 1;

	if (ans <0) {
		ans = 0;
	}
	
	cout << ans << endl;
}