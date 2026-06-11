
// A - Expired?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int X, A, B;
	cin >> X >> A >> B;

	string ans;

	if (B <= A) ans = "delicious";
	else if (B <= A + X) ans = "safe";
	else ans = "dangerous";

	cout << ans << endl;

	return 0;
}