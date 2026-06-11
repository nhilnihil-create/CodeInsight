#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	string s;
	cin >> s;

	// A[i][j] i文字目から遠い
	vector<vector<int>> A(s.size(), vector<int>(26));

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			A[i][j] = s.size() - i;
		}
		for (int j = i; j < s.size(); j++) {
			A[i][s[j] - 'a'] = min(abs(i - j), A[i][s[j] - 'a']);
		}
	}
	vector<int> max_dis(26, 0);
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			// cout << A[i][j] << " ";
			if (A[i][j] != s.size()) {
				max_dis[j] = max(max_dis[j], A[i][j]);
			}
		}
		// cout << "\n";
	}
	int result = s.size();
	for (int j = 0; j < 26; j++) {
		result = min(result, max_dis[j]);
	}

	cout << result;
	return 0;
}