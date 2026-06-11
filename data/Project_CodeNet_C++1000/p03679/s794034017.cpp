#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, a, b; cin >> x >> a >> b;

	if (b <= a) {
		cout << "delicious" << endl;
		return 0;
	}

	string ans;

	if( x + 1 <= b - a) ans = "dangerous";
	else ans = "safe";

	cout << ans << endl;
	return 0;
}