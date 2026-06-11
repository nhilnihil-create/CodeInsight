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

	int n, i, j, k, ans = 0;
	cin >> n;
	vector<int> a(n * 2);
	for (i = 0; i < n * 2; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());
	for (i = 0; i < n; i++) ans += min(a[i * 2], a[i * 2 + 1]);
	cout << ans << "\n";


	return 0;
}
