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

	int n, m, i, j, k, s1 = 0, s2 = 0, s4 = 0;
	cin >> n >> m;
	string s;
	vector<int> ct(26, 0);
	for (i = 0; i < n; i++) {
		cin >> s;
		for (auto ch : s) ct[ch - 'a']++;
	}

	for (i = 0; i < 26; i++) {
		s4 += ct[i] / 4;
		ct[i] %= 4;
	}
	bool ans = false;

	if (s4 >= (n / 2) * (m / 2)) {
		s2 = (s4 - (n / 2) * (m / 2)) * 2;
		for (i = 0; i < 26; i++) {
			s2 += ct[i] / 2;
			ct[i] %= 2;
		}
		if (s2 >= ((n % 2) * (m - m % 2) + (m % 2) * (n - n % 2))/2) {
			s1 = (s2 - ((n % 2) * (m - m % 2) + (m % 2) * (n - n % 2)) / 2) * 2;
			for (i = 0; i < 26; i++) {
				s1 += ct[i];
			}

			if (s1 >= (n % 2) * (m % 2)) {
				ans = true;
			}
		}
	}

	if (ans) cout << "Yes\n";
	else cout << "No\n";


	return 0;
}
