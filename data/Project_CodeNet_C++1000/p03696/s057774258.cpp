#include <iostream>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int x = 0, m = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			x++;
			m = max(m, x);
		} else {
			x--;
		}
	}
	int a = m, b = m - x;
	for (int i = 0; i < a; i++) cout << '(';
	cout << s;
	for (int i = 0; i < b; i++) cout << ')';
	cout << endl;
	return 0;
}