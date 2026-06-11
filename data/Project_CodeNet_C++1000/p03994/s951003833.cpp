#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	int n;
	cin >> s >> n;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') {
			continue;
		}

		int t = 26 - (s[i] - 'a');
		if (t <= n) {
			s[i] = 'a';
			n -= t;
		}
	}

	if (n) {
		int t = n % 26;
		s[s.length() - 1] += t;

		if (s[s.length() - 1] > 'z') {
			s[s.length() - 1] -= 'z' - 'a';
		}
	}
	cout << s << endl;

	return 0;
}