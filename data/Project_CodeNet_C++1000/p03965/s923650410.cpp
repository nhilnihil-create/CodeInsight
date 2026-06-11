
// D - AtCoDeerくんと変なじゃんけん

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const int MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	int ans = 0;

	for (int i=0; i<s.size(); i++) {
		if (i % 2 == 0) {
			if (s[i] == 'p') ans--;
		} else {
			if (s[i] == 'g') ans++;
		}
	}

	cout << ans << endl;

	return 0;
}