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

	long long n, i, j, k, ans, s, ss;
	cin >> n >> k;
	vector<long long> a(n);
	for (i = 0; i < n; i++) cin >> a[i]; 

	s = 0; ss = 0;
	for (i = 0; i < k; i++) ss += a[i];
	for (; i < n; i++) {
		if (a[i] > 0) s += a[i];
	}
	ans = max(0LL, s + ss);

	for (i = 1; i + k <= n; i++) {
		ss = ss + a[i + k - 1] - a[i - 1];
		if (a[i + k - 1] > 0) s -= a[i + k - 1];
		if (a[i - 1] > 0) s += a[i - 1];
		ans = max(ans, s + ss);
		ans = max(ans, s);
	}

	cout << ans << "\n";


	return 0;
}
