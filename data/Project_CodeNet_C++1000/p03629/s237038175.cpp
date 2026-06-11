#include<bits/stdc++.h>
using namespace std;
int n;
char s[500004];
int dp[500002] = {0};
int pre[500002];
int mi[26] = {0};
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	reverse(s + 1, s + n + 1);
	for(int i = 1; i <= n; i ++) {
		int c = 0;
		for(int j = 1; j < 26; j ++) if(dp[mi[j]] < dp[mi[c]]) c = j;
		pre[i] = mi[c];
		dp[i] = dp[mi[c]] + 1;
		mi[s[i] - 'a'] = i;
	}
	int ans = 0;
	for(int i = 1; i < 26; i ++) if(dp[mi[i]] < dp[mi[ans]]) ans = i;
	if(mi[ans] == 0) return putchar(ans + 'a'), 0;
	ans = mi[ans];
	while(pre[ans]) putchar(s[ans]), ans = pre[ans];
	putchar(s[ans]);
	bool vis[26] = {0};
	for(int i = 1; i < ans; i ++) vis[s[i] - 'a'] = 1;
	for(int i = 0; i < 26; i ++)
		if(! vis[i]) {
			putchar(i + 'a');
			break;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}