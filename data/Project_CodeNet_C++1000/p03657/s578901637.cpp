
// A - Sharing Cookies

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int A, B;
	cin >> A >> B;

	string ans;

	if (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) {
		ans = "Possible";
	} else {
		ans = "Impossible";
	}

	cout << ans << endl;

	return 0;
}