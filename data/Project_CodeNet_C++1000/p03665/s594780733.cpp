#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;

const ll mod = 1000000007;


ll pow2(int n) {
	ll ans = 1;
	rep(i, n) {
		ans *= 2;
	}
	return ans;
}

int main() {
	int n, p;

	cin >> n >> p;

	int odd = 0;
	int even = 0;

	rep (i, n) {
		int a;
		cin >> a;
		if (a & 1) {
			odd++;
		} else {
			even++;
		}
	}

	if (p == 1 && odd == 0) {
		cout << 0 << endl;
	} else if (p == 0 && odd == 0) {
		cout << pow2(n) << endl;
	} else {
		cout << pow2(n - 1) << endl;
	}



	return 0;
}
