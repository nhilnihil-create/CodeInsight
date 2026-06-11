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

	long long n, i, j, k, s, ss, d;
	cin >> n;
	vector<long long> a(n);
	s = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	ss = n * (n + 1) / 2;

	bool valid = true;
	if (s % ss != 0) valid = false;
	else {
		k = s / ss;
		for (i = 0; i < n; i++) {
			d = a[(i + 1) % n] - a[i];
			if ((k - d < 0) || ((k - d) % n != 0)) valid = false;
		}
	}

	if (valid) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}

