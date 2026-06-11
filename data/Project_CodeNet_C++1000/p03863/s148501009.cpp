
// D - An Ordinary Game

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const int MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	bool c1 = (s.size() % 2 == 0);
	bool c2 = (s[0] == s[s.size() - 1]);

	string ans;
	if (c1 == c2) ans = "First";
	else ans = "Second";

	cout << ans << endl;

	return 0;
}