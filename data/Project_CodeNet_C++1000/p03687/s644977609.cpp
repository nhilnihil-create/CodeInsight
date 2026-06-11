#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string s, char c);

int main()
{
	string s;
	cin >> s;

	int ans = 1010101010;
	string t, t_;
	for (char c = 'a'; c <= 'z'; c++) {
		t = s;

		for (int i = 0; i < s.length(); i++) {
			if (check(t, c)) {
				ans = min(i, ans);
				break;
			}

			t_ = "";
			for (int j = 0; j < t.length() - 1; j++) {
				if (t[j] == c || t[j + 1] == c) {
					t_ += c;
				} else {
					t_ += t[j];
				}
			}
			t = t_;
		}
	}
	cout << ans << endl;

	return 0;
}

bool check(string s, char c)
{
	bool ret = true;

	for (char sc : s) {
		if (sc != c) {
			ret = false;
			break;
		}
	}
	return ret;
}