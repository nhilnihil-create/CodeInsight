#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	bool a = 0;
	int n = s.length();
	if (n == 2 && s[0] == s[1]) {
		cout << 1 << " " << 2;
		a = 1;
	}
  
	if (a == 0)
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == s[i + 1] || s[i] == s[i + 2]) {
			cout << i + 1 << " " << i + 3;
			a = 1;
			break;
		}
	}
	
	if (a == 0) {
		if (s[n - 2] == s[n - 1]) cout << n - 2 << " " << n;
		else cout << -1 << " " << -1;
	}
}