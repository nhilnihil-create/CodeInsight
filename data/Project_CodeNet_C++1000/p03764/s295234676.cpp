# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
using namespace std;
using LL = long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1000000000;
const double PI = acos(-1);

int main() {
	int n, m;
	cin >> n >> m;
	vector<LL> x(n + 1), y(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> y[i];
	}

	LL v = 0;
	for (int i = 1; i <= n; i++) {
		v += (i + i - n - 1) * x[i];
		v %= (LL)1e9 + 7;
	}

	LL d = 0;
	for (int i = 1; i <= m; i++) {
		d += (i + i - m - 1) * y[i];
		d %= (LL)1e9 + 7;
	}

	cout << (v * d) % (MOD) << endl;
}