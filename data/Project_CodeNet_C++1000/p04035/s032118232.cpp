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
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;



int main() {
	int n;
	ll l;

	cin >> n >> l;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int last = -1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] + a[i + 1] >= l) {
			last = i;
			break;
		}
	}

	if (last < 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;

	for (int i = 0; i < last; i++) {

		cout << i + 1 << endl;
	}

	for (int i = n - 2; i >= last; i--) {

		cout << i + 1 << endl;
	}

}