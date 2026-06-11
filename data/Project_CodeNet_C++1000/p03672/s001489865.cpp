#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
bool isgusu(string s) {
	int n = s.size();
	string x = s.substr(0, n/2);
	string y = s.substr(n/2, n/2);
	return x == y;
} 
int main() {
	string s; cin >> s;
	rep(i, s.size()) {
		string ss = s.substr(0, s.size()-i-1);
		int l = ss.size();
		if (l % 2 != 0) continue;
		if (isgusu(ss)) {
			cout << l << endl;
			return 0;
		}
	}
	return 0;
}