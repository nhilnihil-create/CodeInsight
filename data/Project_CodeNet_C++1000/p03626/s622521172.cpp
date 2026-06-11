#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;

	string s = "";
	for (int i = 0; i < n; i++) {
		if (s1[i] == s2[i]) {
			s += "X";
		} else {
			s += "Y";
			i++;
		}
	}

	long long ans = (s[0] == 'X') ? 3 : 6;
	int mod = 1000000007;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] == 'X') {
			if (s[i] == 'X') {
				ans *= 2;
			} else {
				ans *= 2;
			}
		} else {
			if (s[i] != 'X') {
				ans *= 3;
			}
		}
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}