#include <bits/stdc++.h>

using namespace std;

int N, dp[200005];
int nex[200005][26];
int rev[200005];
int str[200005];
int last[26];
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	N = s.size();
	for (int i = 1; i <= N; ++i){
		str[i] = s[i-1] - 'a';
	}
	for (int i = 0; i < 26; ++i){
		last[i] = N+1;
		dp[N+1] = 0;
	}

	for (int i = N; i >= 0; --i){
		dp[i] = 1e9;
		for (int j = 0; j < 26; ++j){
			nex[i][j] = last[j];
			last[j] = (str[i] == j ? i : last[j]);
			if (dp[nex[i][j]] + 1 < dp[i]){
				rev[i] = j;
				dp[i] = dp[nex[i][j]] + 1;
			}
		}
	}
	s.clear();
	int cur = 0;
	while (cur != N+1){
		s.push_back((char) ('a' + rev[cur]));
		cur = nex[cur][rev[cur]];
	}
	cout << s << '\n';
}