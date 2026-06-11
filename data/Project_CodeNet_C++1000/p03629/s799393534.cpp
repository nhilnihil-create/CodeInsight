#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int MAXN = 3e5;
int N;
char A[MAXN];

int nxt[MAXN][26]; // current # done, next index
int dp[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> A;
	N = int(strlen(A));

	for (int c = 0; c < 26; c++) {
		nxt[N][c] = N;
	}
	for (int i = N-1; i >= 0; i--) {
		for (int c = 0; c < 26; c++) {
			nxt[i][c] = nxt[i+1][c];
		}
		nxt[i][int(A[i] - 'a')] = i;
	}

	// reach N+1
	dp[N+1] = 0;
	for (int i = N; i >= 0; i--) {
		dp[i] = INF;
		for (int c = 0; c < 26; c++) {
			dp[i] = min(dp[i], dp[nxt[i][c] + 1] + 1);
		}
	}

	int cur = 0;
	string ans;
	while (cur != N+1) {
		int c = 0;
		while (dp[cur] != dp[nxt[cur][c] + 1] + 1) {
			c++;
		}
		ans += char(c + 'a');
		cur = nxt[cur][c] + 1;
	}
	cout << ans << '\n';

	return 0;
}