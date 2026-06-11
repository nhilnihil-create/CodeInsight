
// B - OddString

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string s, ans;
	cin >> s;

	for (int i=0; i<s.size(); i+=2) {
		ans.push_back(s[i]);
	}

	cout << ans << endl;

	return 0;
}