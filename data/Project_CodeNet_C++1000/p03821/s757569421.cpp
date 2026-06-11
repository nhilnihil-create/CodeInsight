#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>ab(n, vector<int>(2));
	for (int i = 0; i < n; i++)cin >> ab.at(i).at(0) >> ab.at(i).at(1);
	for (int i = 0; i < n; i++)ab.at(i).at(0) = ab.at(i).at(0) % ab.at(i).at(1);
	long long ans = 0;
	for (int i = n-1; i >= 0; i--) {
		if ((ab.at(i).at(0) + ans) % ab.at(i).at(1) == 0)continue;
		else ans += ab.at(i).at(1) - ((ab.at(i).at(0) + ans) % ab.at(i).at(1));
	}
	cout << ans << endl;
}