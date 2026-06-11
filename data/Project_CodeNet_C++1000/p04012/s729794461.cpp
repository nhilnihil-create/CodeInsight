#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.length() % 2) {
		cout << "No\n";
		return 0;
	}
	char* c = new char[s.length()];
	for (int i = 0;i < s.length();i++) {
		c[i] = s[i];
	}
	sort(c, c + s.length());
	for (int i = 0;i < s.length();i += 2) {
		if (c[i] != c[i + 1]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes\n";
}
