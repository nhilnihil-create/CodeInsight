#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int t = s.size() - 2;
	string ans = "";
	ans += s[0];
	ans += to_string(t);
	ans += s[s.size() - 1];
	cout << ans << endl;
	return 0;
}