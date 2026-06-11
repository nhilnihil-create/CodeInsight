#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>babo(n, vector<int>(2,1));
	babo.at(0).at(1) = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y , x--, y--;
		babo.at(x).at(0)--;
		babo.at(y).at(0)++;
		if (babo.at(x).at(1) == 0)babo.at(y).at(1) = 0;
		if (babo.at(x).at(0) == 0)babo.at(x).at(1) = 1;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (babo.at(i).at(1) == 0)ans++;
	}
	cout << ans << endl;

}