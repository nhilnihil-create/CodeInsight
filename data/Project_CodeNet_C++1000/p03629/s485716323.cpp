#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
const int MAXN = 200005;
const int INF = (LL)1e9 + 5;

int dp[30];
char best[MAXN];
string s, ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	int len = 1;
	best[s.size()] = 'a';
	for (int i = 0; i < 26; i++) dp[i] = 1;
	
	for (int i = s.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			dp[j] = s[i] - 'a' == j ? len + 1 : dp[j];
		}
		
		best[i] = min_element(dp, dp + 26) - dp + 'a';
		len = dp[best[i] - 'a'];
	}
	
	int i = 0;
	while (i <= s.size()) {
		ans.push_back(best[i]);
		while (i < s.size() && s[i] != ans.back()) i++;
		i++;
	}
	
	cout << ans << "\n";
	
	return 0;
	
	/**** Note MAXN ****/
}
