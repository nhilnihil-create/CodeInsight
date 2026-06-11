#include <iostream>
#include <string>
#include <string_view>
using namespace std;
const int INF = 1e9;
template<typename T> bool chmin(T &a, T b) { return a > b && (a = b, true); }

int main() {
	int n; cin >> n;
	string s, t; cin >> s >> t;

	string tmp;
	int ans = INF;
	for (int i = 0; i <= t.length(); i++) {
		tmp = s;
		tmp = s + t.substr(t.length() - i);
		if (tmp.substr(0, n) == s &&
		    tmp.substr(i, n) == t)
                chmin(ans, (int)tmp.length());
	}

	cout << ans << endl;
}
