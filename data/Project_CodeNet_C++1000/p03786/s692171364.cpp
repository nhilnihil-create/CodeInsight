#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int, int>;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	int ans = 1;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.rbegin(), a.rend());
	for (int i = 1; i < n; ++i) {
		sum -= a[i - 1];
		if (2 * sum < a[i - 1])	break;
		ans++;
	}
	cout << ans << endl;
	return 0;
}