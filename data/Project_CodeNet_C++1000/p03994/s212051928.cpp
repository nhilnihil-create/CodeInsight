#include <iostream>
using namespace std;
int main(void) {
	string s;
	int k;
	cin >> s >> k;
	string ans = "";
	for (int i = 0; i < s.size(); ++i) {
		if (i != s.size() - 1) {
			if (s[i] == 'a') ans += 'a';
			else if (123 - s[i] <= k) {
				k -= 123 - s[i];
				ans += 'a';
			}
			else {
				ans += s[i];
			}
		}
		else {
			int num = (s[i] - 97 + k) % 26 + 97;
			ans += char(num);
		}
	}
	cout << ans << "\n";
	return 0;
}