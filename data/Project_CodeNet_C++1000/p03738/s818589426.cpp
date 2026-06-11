#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string a, b; cin >> a >> b;
	
	string ans;
	if (a.size() < b.size()) {
		ans = "LESS";
	}

	else if (b.size() < a.size()) {
		ans = "GREATER";
	}
	else { // a.size() == b.size()
		if (a < b) ans = "LESS";
		else if (b < a) ans = "GREATER";
		else ans = "EQUAL";
	}

	cout << ans << endl;
	return 0;
}