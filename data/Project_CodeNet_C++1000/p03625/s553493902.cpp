#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (mp.count(a)) mp[a]++;
		else mp[a] = 1;
	}

	vector<pair<int, int>> length_count;
	for (const auto& item : mp) length_count.push_back(make_pair(item.first, item.second));
	sort(length_count.begin(), length_count.end(), greater<pair<int, int>>());

	vector<ll> side;
	int count = 0;
	for (const auto& item : length_count) {
		if (4 <= item.second) {
			side.push_back(item.first);
			side.push_back(item.first);
			count += 2;
		}
		else if (2 <= item.second) {
			side.push_back(item.first);
			count++;
		}
		if (count == 2) break;
	}
	if (count < 2) cout << 0 << endl;
	else cout << side[0] * side[1] << endl;
}
