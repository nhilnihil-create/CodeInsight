#include<bits/stdc++.h>

int main(){
	int n, ma, mb;
	scanf("%d %d %d", &n, &ma, &mb);
	
	int dp[1+n][420][420];
	for(int i=0; i<1+n; i++) for(int j=0; j<420; j++) std::fill_n(dp[i][j], 420, 10000);
	dp[0][0][0] = 0;

	for(int i=0; i<n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		for(int A=0; A<419-a; A++){
			for(int B=0; B<419-b; B++){
				dp[i+1][A][B] = std::min(dp[i+1][A][B], dp[i][A][B]);
				dp[i+1][A+a][B+b] = std::min(dp[i+1][A+a][B+b], dp[i][A][B]+c);
			}
		}
	}
	
	int ans = 10000;
	for(int i=1; i<420; i++){
		for(int j=1; j<420; j++){
			if(i*mb==j*ma) ans = std::min(ans, dp[n][i][j]);
		}
	}
	
	if(ans>=10000) puts("-1");
	else printf("%d\n", ans);
	return 0;
}
