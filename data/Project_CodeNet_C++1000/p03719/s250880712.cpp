
// A - Between Two Integers

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	string ans;

	if (A <= C && C <= B) ans = "Yes";
	else ans = "No";

	cout << ans << endl;

	return 0;
}