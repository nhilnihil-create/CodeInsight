#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;


int main() {
	string s;
	cin >> s;

	ll res = 0, pos = 0, ans = 0;
	for (int bit = 0; bit < (1 << s.length() - 1); ++bit) {

		res = 0, pos = 0;
		rep(i, s.length() - 1) {
			pos += int(s[i] - '0');//数値に変換
			if (bit & (1 << i)) {
				res += pos;
				pos = 0;
			}
			else {
				pos = pos * 10;
			}
		}
		pos += int(s[s.length() - 1] - '0');
		ans += res + pos;
	}
	cout << ans << endl;
}
