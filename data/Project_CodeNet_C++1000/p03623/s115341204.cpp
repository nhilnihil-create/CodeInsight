
// A - Meal Delivery

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int x, a, b;
	cin >> x >> a >> b;

	string ans;

	if (abs(x - a) < abs(x - b)) ans = "A";
	else ans = "B";

	cout << ans << endl;

	return 0;
}