#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int a, b, c; cin >> a >> b >> c;
	map<int, int> mp;
	mp[a] = 1;
	mp[b] = 1;
	mp[c] = 1;
	int ans = 0;
	for (auto u : mp) {
		ans += u.second;
	}
	cout << ans << endl;
	return 0;
}