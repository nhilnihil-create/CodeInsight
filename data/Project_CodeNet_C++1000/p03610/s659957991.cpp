#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	string ans = "";
	for (int i = 0; i < s.size(); i += 2) {
		ans.push_back(s[i]);
	}

	cout << ans << endl;
	return 0;
}