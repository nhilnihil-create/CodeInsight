#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 1e5 + 7;
long long N , dp[_][2] , val[_][2] , cnt;

int main(){
	N = read(); val[0][1] = read();
	for(int i = 1 ; i < N ; ++i) if(getchar() == '-') val[++cnt][0] = read(); else val[cnt][1] += read();
	memset(dp , -0x3f , sizeof(dp)); dp[0][0] = 0;
	for(int i = 1 ; i <= cnt ; ++i){
		dp[i][0] = max(dp[i - 1][0] , dp[i - 1][1]) + val[i][1] - val[i][0];
		dp[i][1] = max(dp[i - 1][0] - val[i][0] - val[i][1] , dp[i - 1][1] + val[i][0] + val[i][1]);
	}
	cout << max(dp[cnt][0] , dp[cnt][1]) + val[0][1];
	return 0;
}