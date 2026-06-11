
// A - ι⊥l

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	string ans;

	if (b - a == c - b) ans = "YES";
	else ans = "NO";

	cout << ans << endl;

	return 0;
}