#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long ll;




int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll cur = 1, ans = 0; int pos = 0;
	while (true) {
		while (pos < n && a[pos] < cur) pos++;
		if (pos >= n) break;
		if (a[pos] == cur) cur++;
		else ans += (a[pos] - 1) / cur, a[pos] = 1;
	}
	cout << ans << endl;
	return 0;
}
