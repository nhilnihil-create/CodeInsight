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
#include <numeric>
#include <math.h> 

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, k, i, j, ans, maxx, x, ct, s;
	cin >> n >> k;
	vector<long long> a(n), v;
	for (i = 0; i < n; i++) cin >> a[i];

	ans = 1LL << 61;

	for (i = 0; i < (1 << n); i++) {
		ct = 0;
		maxx = 0;
		s = 0;

		for (j = 0; j < n; j++) {
			if (a[j] > maxx) {
				maxx = a[j];
				ct++;
			}
			else if (i & (1 << j)) {
				x = maxx + 1 - a[j];
				s += x;
				ct++;
				maxx++;
			}
		}

		if (ct >= k) ans = min(ans, s);
	}

	cout << ans << "\n";


	return 0;
}

