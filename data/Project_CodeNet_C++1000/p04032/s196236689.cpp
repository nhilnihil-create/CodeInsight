#include <bits/stdc++.h>

using namespace std;

int main() {

	string str; cin >> str;

	for (int i = 0; i < str.length() - 1; i++) {

		if (str[i] == str[i + 1]) {

			cout << i + 1 << " " << i + 2 << "\n";
			return 0;

		}

		if (i + 2 >= str.length()) continue;

		if (str[i] == str[i + 2]) {

			cout << i + 1 << " " << i + 3 << "\n";
			return 0;

		}

	}

	cout << "-1 -1\n";

	return 0;

}