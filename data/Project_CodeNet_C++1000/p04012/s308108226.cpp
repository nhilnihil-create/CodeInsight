#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	vector <int>v;
	for (int i = 0; i < s.length(); i++) {
		int c = count(s.begin(), s.end(), s[i]);
		v.push_back(c);
	}
	int x = 0;
	for (int j = 0; j < v.size(); j++) {
		if (v[j] % 2 != 0) {
			x++;
		}
	}
	if (x == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
