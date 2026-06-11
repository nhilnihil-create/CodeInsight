#include <bits/stdc++.h>
using namespace std;

int numdif(string s, string t) {
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] != t[i])
			ans++;
	cout << ans;
}

int main() {
	string s;
	cin >> s;
	numdif(s, "CODEFESTIVAL2016");
}
