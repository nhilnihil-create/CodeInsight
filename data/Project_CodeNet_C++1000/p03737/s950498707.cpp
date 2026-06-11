
// A - Three-letter acronym

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	string ans = "";
	ans += toupper(s1[0]);
	ans += toupper(s2[0]);
	ans += toupper(s3[0]);

	cout << ans << endl;

	return 0;
}