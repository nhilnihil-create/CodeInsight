#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, m, i, j, k, ans, a, b, c, minn, maxx;
	cin >> n >> m;
	ans = n * m;
	if (n % 3 == 0) ans = 0;
	else ans = min(ans, m);
	if (m % 3 == 0) ans = 0;
	else ans = min(ans, n);
	for (i = 1; i < n; i++) {
		a = i * m;
		b = (n - i) * (m / 2);
		c = n * m - a - b;

		minn = min(a, min(b, c));
		maxx = max(a, max(b, c));
		ans = min(ans, maxx - minn);
	}
	for (i = 1; i < m; i++) {
		a = i * n;
		b = (m - i) * (n / 2);
		c = n * m - a - b;

		minn = min(a, min(b, c));
		maxx = max(a, max(b, c));
		ans = min(ans, maxx - minn);
	}
	cout << ans << "\n";


	return 0;
}
