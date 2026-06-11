#include<bits/stdc++.h>

using namespace std;

int main() {

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	int change = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] != s[i - 1]) change++;
	}
	cout << change << '\n';
	return 0;
}