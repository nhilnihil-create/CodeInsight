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
	
	long long n, i, j, k, ans, a, b;
	cin >> n >> a >> b;
	vector<long long> x(n);
	for (i = 0; i < n; i++) cin >> x[i];
	ans = 0;
	for (i = 1; i < n; i++) ans += min(a * (x[i] - x[i - 1]), b);
	cout << ans << "\n";

	return 0;
}

