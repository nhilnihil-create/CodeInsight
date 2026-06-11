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

	long long n, a, b, i, j, k, sa, ans, si, x;
	cin >> n >> a >> b;
	vector<long long> v(n), s(n + 1);
	map<long long, long long> ct, ct2;
	for (i = 0; i < n; i++) {
		cin >> v[i];
		ct[v[i]]++;
	}
	sort(v.rbegin(), v.rend());
	s[0] = 0;
	for (i = 1; i <= n; i++) s[i] = s[i - 1] + v[i - 1];
	sa = s[a];

	ans = 0;
	for (i = a; i <= b; i++) {
		si = s[i];
		if (si * a == sa * i) {
			ct2.clear();
			for (j = 0; j < i; j++) ct2[v[j]]++;

			x = 1;
			for (j = 0; j < ct2[v[i - 1]]; j++) {
				x = x * (ct[v[i - 1]] - j) / (j + 1);
			}
			ans += x;
		}
	}

	long double r = 1.0 * sa / a;
	cout << setprecision(10) << fixed << r << "\n" << ans << "\n";


	return 0;
}
