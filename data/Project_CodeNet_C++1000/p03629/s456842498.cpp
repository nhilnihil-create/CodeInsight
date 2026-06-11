#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
const int MAXN = 200005;
const int INF = (LL)1e9 + 5;

string s;
int dp[MAXN][30];
char add[MAXN][30] = {0};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for (int i = 0; i < 26; i++) {
		dp[s.size()][i] = 1;
	}
	
	for (int i = s.size() - 1; i >= 0; i--) {
		int pos = min_element(dp[i + 1], dp[i + 1] + 26) - dp[i + 1];
		int len = dp[i + 1][pos];
		for (int j = 0; j < 26; j++) {
			if (s[i] == j + 'a') {
				dp[i][j] = len + 1;
				add[i][j] = pos;
			}
			else {
				dp[i][j] = dp[i + 1][j];
				add[i][j] = -1;
			}
		}
	}
	
	string ans;
	int cur = min_element(dp[0], dp[0] + 26) - dp[0];
	ans.push_back(cur + 'a');
	for (int i = 0; i < s.size(); i++) {
		if (add[i][cur] != -1) {
			ans.push_back(add[i][cur] + 'a');
			cur = add[i][cur];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
	
	/**** Note MAXN ****/
}
