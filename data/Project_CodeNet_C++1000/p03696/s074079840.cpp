#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	string s;
	cin >> n >> s;
	ll hi = 0;
	ll to = 0;
	for (char c : s) {
		if (c == '(') {
			++to;
		}
		else {
			if (to > 0)--to;
			else ++hi;
		}
	}
	string ans;
	for (ll i = 0; i < hi; ++i)ans += "(";
	ans += s;
	for (ll i = 0; i < to; ++i)ans += ")";
	cout << ans << endl;
}
