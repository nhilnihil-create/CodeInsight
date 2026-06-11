#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 55;
int n, m;
pair<int, int> person[N], check[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> person[i].first >> person[i].second;
	for(int i = 1; i <= m; i++)
		cin >> check[i].first >> check[i].second;

	for(int i = 1; i <= n; i++) {
		int ans = -1, best = 1e9;
		for(int j = 1; j <= m; j++) {
			if(best > abs(person[i].first - check[j].first) + abs(person[i].second - check[j].second)) {
				best = abs(person[i].first - check[j].first) + abs(person[i].second - check[j].second);
				ans = j;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}