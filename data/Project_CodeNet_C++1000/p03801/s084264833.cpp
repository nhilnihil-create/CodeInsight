#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> a(n + 1);
	for (int i = 1;i <= n;++i) {
		int x;
		cin >> x;
		a[i] = {x,-i};
	}
	sort(a.begin() + 1,a.end());
	reverse(a.begin() + 1,a.end());
	vector<long long> cnt(n + 1);
	a.emplace_back(0,0);
	int mx = -1e9;
	int count = 0;
	for (int i = 1;i <= n;++i) {
		int j = i + 1;
		while (j <= n && a[i].first == a[j].first) ++j;
		mx = max(mx,a[i].second);
		count += j-i;
		cnt[-mx] += 1ll * count * (a[i].first - a[j].first);
		i = j-1;
	}
	for (int i = 1;i <= n;++i) cout << cnt[i] <<"\n";
}