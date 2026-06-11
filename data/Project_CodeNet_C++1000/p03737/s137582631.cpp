#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string a, b, c; cin >> a >> b >> c;
	string ans = "";
	ans += 'A' + (a[0] - 'a');
	ans += 'A' + (b[0] - 'a');
	ans += 'A' + (c[0] - 'a');
	cout << ans << endl;
	return 0;
}