#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> score(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cin >> score.at(i).at(0) >> score.at(i).at(1);
	}
	sort(score.begin(), score.end());
	int ans = score.at(n - 1).at(0) + score.at(n - 1).at(1);
	cout << ans << endl;
}