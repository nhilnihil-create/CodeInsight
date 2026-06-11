#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<char> c;
	int t = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'S') {
			c.push('S');
		} else {
			if (!c.empty()) {
				c.pop();
				t += 2;
			}
		}
	}
	cout << s.length() - t << endl;

	return 0;
}