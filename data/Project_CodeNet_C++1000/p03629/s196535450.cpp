#include <iostream>
#include <string>
#define llint long long
#define inf 1e9

using namespace std;

string s;
int succ[200005][26];
int dp[200005];
int nx[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	int n = s.size();
	s = "#" + s;
	
	for(int i = 0; i < 26; i++) nx[i] = n+1; 
	for(int i = n; i >= 1; i--){
		for(int j = 0; j < 26; j++) succ[i][j] = nx[j];
		nx[s[i]-'a'] = i;
	}
	for(int i = 0; i < 26; i++) succ[0][i] = nx[i];
	
	for(int i = 0; i <= n+1; i++) dp[i] = inf;
	dp[n+1] = 0;
	
	for(int i = n; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			dp[i] = min(dp[i], dp[succ[i][j]]+1);
		}
	}
	
	int p = 0; string ans;
	while(p < n+1){
		for(int j = 0; j < 26; j++){
			if(dp[p] == dp[succ[p][j]]+1){
				p = succ[p][j];
				ans += j+'a';
				break;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}