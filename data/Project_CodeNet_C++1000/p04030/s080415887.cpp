#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	string s;
	cin >> s;

	string ans = "";

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'B' && ans.length() != 0) {
			ans = ans.substr(0, ans.length() - 1);
		}
		else if (s[i] != 'B') {
			ans += s.substr(i, 1);
		}
		else {
			continue;
		}
	}

	cout << ans << endl;

	return 0;
}