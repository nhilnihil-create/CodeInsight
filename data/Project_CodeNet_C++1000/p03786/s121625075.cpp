#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vector<ll> a(n);
	rep(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());

	vector<ll> s(n + 1), t(n + 1);
	rep(i, 0, n) s[i + 1] = s[i] + a[i];

	rep(i, 0, n - 1) {
		if (s[i + 1] * 2 < a[i + 1]) t[i + 1] = 0;
		else t[i + 1] = t[i] + 1;
	}
	cout << t[n - 1] + 1 << endl;
	return 0;
}
