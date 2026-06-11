#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int x; cin >> x;
	int ans = 0, cur = 0;
	while(cur < x)
		ans++, cur+=ans;
	cout << ans << '\n';

	return 0;
}