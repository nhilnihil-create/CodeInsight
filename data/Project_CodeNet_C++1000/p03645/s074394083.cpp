#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n, m;
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	pair<int, int> arr[m];
	map<int, int> mp;
	for (int i = 0; i < m; i++) {
		cin >> arr[i].first >> arr[i].second;

	}
	sort(arr, arr + m);
	for (int i = 0; i < m; i++) {
		if (arr[i].first == 1) {
			mp[arr[i].second] = 1;
		} else
			break;

	}
	for (int i = 0; i < m; i++) {
		if (arr[i].second == n) {
			if (mp[arr[i].first])
				mp[arr[i].first]++;
		}
	}
	for (auto i : mp) {
		if (i.second == 2)
			return cout << "POSSIBLE\n", 0;
	}
	cout << "IMPOSSIBLE\n";
}
