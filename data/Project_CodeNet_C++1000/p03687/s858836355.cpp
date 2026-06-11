
// A - Shrinking

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

bool done(string t, char c) {
	bool res = true;
	for (int i=0; i<t.size(); i++) {
		if (t[i] != c) {
			res = false;
			break;
		}
	}

	return res;
}

int main() {
	string s;
	cin >> s;

	int ans = INF;
	for (char c='a'; c<='z'; c++) {
		int cnt = 0;
		string t = s;
		for (int i=t.size()-1; i>=0; i--) {
			//cout << t << endl; // **** debug ****
			if (done(t, c)) break;
			cnt++;
			string u = "";

			for (int j=0; j<i; j++) {
				if (t[j] == c || t[j+1] == c) u.push_back(c);
				else u.push_back(t[j]);
			}
			t = u;
		}
		ans = min(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}