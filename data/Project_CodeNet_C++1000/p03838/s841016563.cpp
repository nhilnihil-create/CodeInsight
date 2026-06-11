#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll x, y;
	cin >> x >> y;
	if (x == y) {
		cout << 0 << endl;
	} else if (x > y) {
		cout << min(2 + abs(x - y), 1 + abs(x + y));
	} else {
		cout << min(abs(y - x), abs((-y) - x) + 1);
	}

	return 0;

}
