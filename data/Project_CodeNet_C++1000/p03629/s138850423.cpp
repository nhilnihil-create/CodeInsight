#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, p[26][200009], dp[200009], cnt[26]; string s;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> s; s = '#' + s;
	int n = s.size();
	for (int i = 0; i < 26; i++) {
		p[i][n] = n + 1;
		for (int j = n - 1; j >= 0; j--) {
			p[i][j] = (s[j + 1] == i + 97 ? j + 1 : p[i][j + 1]);
		}
	}
	for (int i = n; i >= 0; i--) {
		dp[i] = n + 1;
		for (int j = 0; j < 26; j++) {
			dp[i] = min(dp[i], dp[p[j][i]] + 1);
		}
	}
	string ret;
	int ptr = 0;
	for (int i = dp[0] - 1; i >= 1; i--) {
		for (int j = 0; j < 26; j++) {
			if (dp[p[j][ptr]] == i) {
				ptr = p[j][ptr];
				ret += j + 97;
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (p[i][ptr] == n + 1) {
			ret += i + 97;
			break;
		}
	}
	cout << ret << "\n";
	return 0;
}