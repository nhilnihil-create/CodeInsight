
// A - HonestOrDishonest

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	char a, b;
	cin >> a >> b;

	char ans;
	if (a == 'H') {
		if (b == 'H') ans = 'H';
		else ans = 'D';
	} else {
		if (b == 'H') ans = 'D';
		else ans = 'H';
	}

	cout << ans << endl;

	return 0;
}