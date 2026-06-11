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

	int n, i, j, k, x, ans;
	set<int> a, b;
	vector<int> c;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x;
		if (i % 2 == 0) a.insert(x);
		c.push_back(x);
	}
	sort(c.begin(), c.end());

	ans = 0;
	for (i = 1; i < n; i+=2) {
		if (a.find(c[i]) != a.end()) {
			ans++;
		}
	}
	cout << ans << "\n";


	return 0;
}

