#include<iostream>
using namespace std;

int main() {
	string s; cin >> s;

	for (char c = 'a'; c <= 'z'; c++) {
		bool ok = false;
		for (int i = 0; i < s.size(); i++) {
			if (c == s[i])ok = true;
		}
		if (!ok) {
			cout << c << endl;
			return 0;
		}
	}
	cout << "None" << endl;

	return 0;
}