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

	string s;
	cin >> s;
	long long n = s.length(), ans = n * (n - 1) / 2, i, j, k;
	vector<long long> ct(26, 0);
	for (i = 0; i < n; i++) ans -= ct[s[i] - 'a']++;
	cout << ans + 1 << "\n";

	return 0;
}

