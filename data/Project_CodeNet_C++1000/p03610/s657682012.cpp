
#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

#include <climits>

using namespace std;

int main()

{
	string s;
	cin >> s;

	string ans="";

	for (int i = 0; i < s.size(); i++) {
		if ((i + 1 ) % 2 != 0) {
			ans = ans + s[i];
		}
	}

	cout << ans << endl;

	return 0;

}