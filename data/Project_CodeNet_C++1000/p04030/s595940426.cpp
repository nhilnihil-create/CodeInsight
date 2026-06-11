#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	vector <char> v;
	string r = "";
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i]);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '1' || v[i] == '0') {
			r = r + v[i];
		}
		else {
			r = r.substr(0, r.length() - 1);
		}
	}
	cout << r;

}
