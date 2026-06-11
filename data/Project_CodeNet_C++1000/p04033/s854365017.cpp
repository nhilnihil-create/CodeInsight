
// A - Range Product

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int a, b;
	cin >> a >> b;

	string ans;

	if (a > 0) {
		ans = "Positive";
	} else if (b < 0) {
		if ((b - a) % 2 == 1) ans = "Positive";
		else ans = "Negative";
	} else {
		ans = "Zero";
	}

	cout << ans << endl;

	return 0;
}