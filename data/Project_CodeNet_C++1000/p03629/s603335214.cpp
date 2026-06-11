#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
int nxt[200001][26];
int dp[200001];
int main() {
	string A;
	cin >> A;
	int N = A.size();
	memset(nxt, -1, sizeof(nxt));
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < 26; j++) {
			nxt[i - 1][j] = nxt[i][j];
		}
		nxt[i - 1][A[i - 1] - 'a'] = i;
	}
	for (int i = N; i > 0; i--) {
		bool all = 1;
		int len = 1 << 30;
		for (int j = 0; j < 26; j++) {
			if (nxt[i][j] == -1) {
				all = 0;
				break;
			}
			else {
				len = min(len, dp[nxt[i][j]]);
			}
		}
		if (all) dp[i] = len + 1;
		else dp[i] = 2;
	}
	string ans = "";
	int now = 0;
	while (1) {
		int to = -1;
		for (int i = 0; i < 26; i++) {
			if (nxt[now][i] == -1) {
				ans += string(1, 'a' + i);
				cout << ans << endl;
				return 0;
			}
			if (to == -1 || dp[nxt[now][to]] > dp[nxt[now][i]]) to = i;
		}
		ans += string(1, 'a' + to);
		now = nxt[now][to];
	}
 }