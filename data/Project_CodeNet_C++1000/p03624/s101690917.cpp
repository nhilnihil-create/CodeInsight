#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	vector<int> letter(26, 0);
	string s;
	cin >> s;
	rep(i,s.size()) {
		char c = s[i];
		letter[c-'a']++;
	}
	rep(i, 26) {
		if (letter[i] == 0) {
			cout << char('a' + i) << endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;
}