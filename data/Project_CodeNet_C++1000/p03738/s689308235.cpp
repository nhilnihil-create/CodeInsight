
// B - Comparison

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string A, B;
	cin >> A >> B;

	string ans;
	if (A.size() > B.size()) {
		ans = "GREATER";
	} else if (A.size() < B.size()) {
		ans = "LESS";
	} else {
		if (A > B) {
			ans = "GREATER";
		} else if (A < B) {
			ans = "LESS";
		} else {
			ans = "EQUAL";
		}
	}

	cout << ans << endl;

	return 0;
}