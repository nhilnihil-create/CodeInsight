
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e9
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;

int n, a, b;
int h[100010];

bool enough(ll t) {
	ll times = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] - b * t < 0)continue;
		times += ((h[i] - b * t) + (a - b - 1)) / (a - b);
	}
	return times <= t;
}

int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)cin >> h[i];

	ll left = 0, right = INF;
	while (right - left > 1) {
		ll mid = (left + right) / 2;
		if (!enough(mid))left = mid;
		else right = mid;
	}

	cout << right << endl;

	return 0;
}