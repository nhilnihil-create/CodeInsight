#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long  ll;

int main() {
	string str;
	cin >> str;
	bool same = true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != str[0]) same = false;
	}
	if (same) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1000;
	for (char c = 'a'; c < 'a' + 26; c++)
	{
		ll cnt = 0;
		bool flag = true;
		string temp = str;
		while (flag && temp.length() > 1) {
			flag = false;
			for (size_t i = 0; i < temp.length() - 1; i++)
			{
				string n;
				if (temp[i] == c || temp[i + 1] == c) {
					temp[i] = c;
				}
				else {
					flag = true;
				}
			}
			temp = temp.substr(0, temp.length() - 1);
			cnt++;
		}
		ans = min(cnt, ans);
	}
	cout << ans << endl;
	return 0;
}