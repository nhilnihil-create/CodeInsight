#include <iostream>
using namespace std;
string S;
int ne[200010][26] = {{0}};
int dp[200010] = {0},inf = 1e9;

int main(){
	cin >> S;
	int N = S.size();
	for(int i=0;i<=N+1;i++){
		dp[i] = inf;
		for(int j=0;j<26;j++){
			ne[i][j] = N;
		}
	}
	dp[N] = 1;
	dp[N+1] = 0;
	for(int i=N-1;i>=0;i--){
		for(char c='a';c<='z';c++){
			if(S[i]==c) ne[i][c-'a'] = i;
			else ne[i][c-'a'] = ne[i+1][c-'a'];
		}
	}
	for(int i=N-1;i>=0;i--){
		for(int j=0;j<26;j++){
			dp[i] = min(dp[i],dp[ne[i][j]+1]+1);
		}
	}
	string ans = "";
	int id = 0;
	while(ans.size()<dp[0]){
		for(char c='a';c<='z';c++){
			if(dp[id]==dp[ne[id][c-'a']+1]+1){
				ans = ans+c;
				id = ne[id][c-'a']+1;
				break;
			}
		}
	}
	cout << ans << endl;
}