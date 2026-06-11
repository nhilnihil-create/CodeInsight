#pragma GCC optimize("Ofast", "unroll-loops")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
	string s; cin >> s;
	int ptr = s.length();
	while (ptr > 0) {
		if (ptr >= 7 && s.substr(ptr - 7, 7) == "dreamer")
			ptr -= 7;
		else if (ptr >= 6 && s.substr(ptr - 6, 6) == "eraser")
			ptr -= 6;
		else if (ptr >= 5 && s.substr(ptr - 5, 5) == "erase")
			ptr -= 5;
		else if (ptr >= 5 && s.substr(ptr - 5, 5) == "dream")
			ptr -= 5;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}