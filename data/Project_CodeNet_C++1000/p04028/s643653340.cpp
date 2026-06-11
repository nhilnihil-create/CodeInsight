#include<bits/stdc++.h>
#define Mod 1000000007
#define Val(x) (((long long)x) % Mod)
#define maxn 5005
using namespace std;
int dp[maxn][maxn];
int Pow(int a,int n){
	int ret = 1;
	int base = a;
	while(n) {
		if(n&1)		ret = Val(ret*base);
		base = Val(base*base);
		n >>= 1;
	}	
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0][0] = 1;
	for(int i=1;i<=5000;i++) {
		dp[i][0] = Val(dp[i-1][0] + dp[i-1][1]);
		for(int j=1;j<=i;j++)
			dp[i][j] = Val(dp[i-1][j+1]+dp[i-1][j-1]+dp[i-1][j-1]);
	}
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int m = (int)s.size();
	
	int ans = Val(dp[n][m]);
	
	int tem = Pow(2,m);
	ans = Val(ans*Pow(tem,Mod-2));
	
	cout << ans << endl;
	return 0;
}
