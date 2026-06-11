#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		char ch = s.at(i);
		if (ch == ',') {
			cout << ' ';
		}
		else {
			cout << ch;
		}
	}
	cout << endl;
}