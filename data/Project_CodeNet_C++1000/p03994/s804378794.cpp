
// C - 次のアルファベット

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	int K;
	cin >> K;

	string t = "";

	for (int i=0; i<s.size(); i++) {
		if (K == 0) {
			t.push_back(s[i]);
		} else if (i == s.size()-1) {
			int c = s[i] - 'a';
			t.push_back((char)(((c + K) % 26) + 'a'));
		} else {
			int c = s[i] - 'a';
			if (c > 0 && c + K >= 26) {
				t.push_back('a');
				K -= 26 - c;
			} else {
				t.push_back(s[i]);
			}
		}
	}

	cout << t << endl;

	return 0;
}