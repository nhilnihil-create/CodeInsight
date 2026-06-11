#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;

	stack<char> c;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			c.push('(');
		} else {
			if (c.empty()) {
				cout << '(';
			} else {
				c.pop();
			}
		}
	}
	cout << s;
	while (!c.empty()) {
		cout << ')';
		c.pop();
	}


	return 0;
}