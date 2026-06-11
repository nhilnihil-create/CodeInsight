#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
#define rrep(i, j, n) for(size_t i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> p(n);

	vector<int> a(n), b(n);
	vector<int> target(n);
	int s = 500000000;
	rep(i, 0, n) {
		cin >> p[i];
		--p[i];
		target[p[i]] = s++;
	}

	a[0] = 1;
	b[0] = target[0] - 1;
	rep(i, 1, n) {
		// target[i] = a[i] + b[i]
		// b[i - 1] > b[i]
		// a[i - 1] < a[i]
		// となるようにtarget[i]を分割
		a[i] = target[i] - b[i - 1] + 1;
		if (a[i] <= a[i - 1]) a[i] = a[i - 1] + 1;
		b[i] = target[i] - a[i];
	}

	rep(i, 0, n) cout << a[i] << " \n"[i == n - 1];
	rep(i, 0, n) cout << b[i] << " \n"[i == n - 1];
	return 0;

}
