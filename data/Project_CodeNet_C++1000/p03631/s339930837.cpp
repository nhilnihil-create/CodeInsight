
// A - Palindromic Number

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string N;
	cin >> N;

	string rN = N;
	reverse(rN.begin(), rN.end());

	string ans;
	if (N == rN) ans = "Yes";
	else ans = "No";

	cout << ans << endl;

	return 0;
}