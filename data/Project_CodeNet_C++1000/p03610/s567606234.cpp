#include<iostream>
#include<string>

using namespace std;

int main() {
	string s,a;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			a = a + s[i];
		}
	}
	cout << a << endl;

	return 0;
}