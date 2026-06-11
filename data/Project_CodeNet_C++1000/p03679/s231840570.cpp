#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x, a, b; cin >> x >> a >> b;
	string ans;
	if (b <= a) ans = "delicious";
	else {
		if (b - a <= x) ans = "safe";
		else ans = "dangerous";
	}	
	cout << ans << endl;
	return 0;
}