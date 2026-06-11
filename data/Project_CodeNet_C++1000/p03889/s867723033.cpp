#include <iostream>
#include <string>
using namespace std;

string s, t;

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'b') t += 'd';
		if (s[i] == 'd') t += 'b';
		if (s[i] == 'p') t += 'q';
		if (s[i] == 'q') t += 'p';
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != t[t.length() - 1 - i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}