#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, int> mp = { {'N',0},{'W',0}, {'S',0}, {'E',0} };
	for (int i = 0; i < s.size(); i++) mp[s[i]]++;
	if (mp['N'] == 0 && mp['S'] != 0) {
		cout << "No" << endl;
		return 0;
	}
	if (mp['S'] == 0 && mp['N'] != 0) {
		cout << "No" << endl;
		return 0;
	}
	if (mp['W'] == 0 && mp['E'] != 0) {
		cout << "No" << endl;
		return 0;
	}
	if (mp['E'] == 0 && mp['W'] != 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
}
