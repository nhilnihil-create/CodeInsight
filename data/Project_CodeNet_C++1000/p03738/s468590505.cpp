#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a;
	cin >> b;
	if (a.length() > b.length()) {
		cout << "GREATER" << endl;
		return 0;
	}
	else if (a.length() < b.length()) {
		cout << "LESS" << endl;
		return 0;
	}
	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) == b.at(i)) continue;
		else if (a.at(i) > b.at(i)) {
			cout << "GREATER" << endl;
			return 0;
		}
		else {
			cout << "LESS" << endl;
			return 0;
		}
	}
	cout << "EQUAL" << endl;
}