#include <bits/stdc++.h>
#include <regex>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	string s;
	cin >> s;
	if (regex_match(s, regex("(dream|dreamer|erase|eraser)*")))
		cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}