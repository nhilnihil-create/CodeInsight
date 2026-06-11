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

	long long n, i, j, k, ans = 0, x;
	cin >> n;
	vector<long long> a(n);
	for (i = 0; i < n; i++) cin >> a[i];

	ans = a[0] - 1; k = 2;
	for (i = 1; i < n; i++) {
		if (a[i] >= k) {
			x = (a[i] - 1) / k;
			ans += x;
			a[i] -= x * k;
			if ((x == 0) && (a[i] == k)) k++;
		}
	}
	cout << ans << "\n";


	return 0;
}
