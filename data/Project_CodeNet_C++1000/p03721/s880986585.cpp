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
#include <utility>

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;



int main() {
	vector<ll> as(100001,0);
	ll n, k;
	cin >> n >> k;
	rep(i, n) {
		ll a, b;
		cin >> a >> b;
		as[a]+= b;
	}
	ll count = 0;
	rep(i, 100001) {
		count += as[i];
		if (count >= k) {
			cout << i << endl;
			return 0;
		}
	}


	return 0;
}
