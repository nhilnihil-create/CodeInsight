#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	string x = "CODEFESTIVAL2016";
	ll ans = 0;
	for (int i = 0; i < x.length(); i++) {
		if (s.at(i) != x.at(i))ans++;
	}
	cout << ans << endl;
}