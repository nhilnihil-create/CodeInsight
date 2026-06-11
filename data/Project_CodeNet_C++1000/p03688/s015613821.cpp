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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	if (a[n - 1] - a[0] > 1) {
		cout << "No" << endl;
		return 0;
	}

	int cnt = 0;
	int al = a[n - 1];
	for (int i = 0; i < n; i++) {
		if (a[i] != al) {
			cnt++;
		}
	}
	//cout << cnt << endl;

	if (cnt == 0) {
		if (n - al == 1) {
			cout << "Yes" << endl;
			return 0;
		}
		if (al * 2 > n) {
			cout << "No" << endl;
			return 0;
		}


	}

	if (al - cnt <= 0) {
		cout << "No" << endl;
		return 0;
	}

	if (cnt < 2 * al - n) {
		cout << "No" << endl;
		return 0;
	}
	


	cout << "Yes" << endl;

}