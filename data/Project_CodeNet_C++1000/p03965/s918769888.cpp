#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end(), greater<char>());
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i < s.size() / 2) {
			if ('g' == s[i]) ++ans;
		}
		else {
			if ('p' == s[i]) --ans;
		}
	}
	cout << ans;
}