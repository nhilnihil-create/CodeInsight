#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	static int nex[200010][26];
	static int dp[200010][26];
	for(int i = 0 ; i < 26 ; i ++){
		dp[s.size()][i] = 1;
	}
	for(int i = s.size()-1 ; i >= 0 ; i --){
		for(int j = 0 ; j < 26 ; j ++){
			nex[i][j] = j;
			dp[i][j] = dp[i+1][j];
		}
		int sma = 200010;
		int x = -1;
		for(int j = 0 ; j < 26 ; j ++){
			if(sma > dp[i+1][j]){
				sma = dp[i+1][j];
				x = j;
			}
		}
		nex[i][s[i]-'a'] = x;
		dp[i][s[i]-'a'] = sma+1;
	}
	
	int sma = 200010;
	int x = -1;
	for(int i = 0 ; i < 26 ; i ++){
		if(sma > dp[0][i]){
			sma = dp[0][i];
			x = i;
		}
	}
	string ret = "";
	for(int i = 0 ; i < s.size() ; i ++){
		if(x == s[i]-'a')ret += s[i];
		x = nex[i][x];
	}
	ret += 'a'+x;
	cout << ret << endl;
}

