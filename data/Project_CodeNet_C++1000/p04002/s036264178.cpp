#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<18;
int n, h, w;
set<pair<int, int>> present, cnt[10];
int sum(int i, int j) {
	if(i <= 0 || i+2>h || j <= 0 || j+2>w) return 0;
	int ans = 0;
	for(int a = 0; a < 3; a++)
		for(int b = 0; b < 3; b++)
			ans += present.count({i+a, j+b});
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> h >> w >> n;
	for(int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		present.insert({x, y});
	}
	for(auto i : present) {
		int x = i.first, y = i.second;
		for(int a = 0; a < 3; a++)
			for(int b = 0; b < 3; b++)
				cnt[sum(x-a, y-b)].insert({x-a, y-b});
	}
	ll p0 = (h-2) * 1ll * (w - 2);
	for(int i = 1; i < 10; i++) p0 -= cnt[i].size();
	cout << p0 << '\n';
	for(int i = 1; i < 10; i++) cout << cnt[i].size() << '\n';
}
