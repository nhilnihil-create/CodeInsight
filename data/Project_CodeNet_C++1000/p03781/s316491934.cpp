#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int X; cin >> X;
	int ans = 0;
	while (ans * 1LL * (ans + 1) / 2 < X) ans++;
	cout << ans << endl;
	return 0;
}
