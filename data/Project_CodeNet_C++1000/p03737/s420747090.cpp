#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	vector<string> s(3);
	for (int i = 0; i < 3; i++) cin >> s[i];
	string ans;
	for (int i = 0; i < 3; i++) {
		ans.push_back(s[i][0] - 'a' + 'A');
	}
	cout << ans << endl;
	return 0;
}