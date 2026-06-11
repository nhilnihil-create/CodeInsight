#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int X,T;
	cin >> X >> T;

	if (X-T>=0) {
		cout << X-T << endl;
	} else if (X-T<0) {
		cout << 0 << endl;
	}
}
