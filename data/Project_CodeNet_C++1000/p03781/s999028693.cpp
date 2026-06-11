#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x; cin >> x;
	int ans;
	for(int i = 1; i <= x; ++ i) {
		if(1LL * i * (i + 1) / 2 >= x) {
			ans = i;
			break;
		}
	}
	cout << ans;
	return 0;
}
