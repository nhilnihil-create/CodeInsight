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

	int n, a, b, ans, i, aa, bb;

	cin >> n >> a >> b;
	ans = a + b;
	aa = a;
	
	for (i = 1; i < n; i++) {
		cin >> a >> b;
		if (a > aa) {
			ans = a + b;
			aa = a;
		}
	}

	cout << ans << "\n";


	return 0;
}


