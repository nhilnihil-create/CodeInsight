#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	string s;
	cin >> s;
	int l = (int)s.size();
	while (l > 0) {
		l--;
		string t, u;
		t = s.substr(0, l / 2);
		u = s.substr(l / 2, l - l / 2);
		if (t == u) break;
	}
	cout << l << endl;
	return 0;
}