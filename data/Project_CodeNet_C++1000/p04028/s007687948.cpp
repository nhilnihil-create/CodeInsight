#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define int long long
using namespace std;
int dp[5140][5140];
int modpow(int x,int k){
	// x ^ k mod inf
	int p2[55],res=1;
	p2[0]=1;p2[1]=x%inf;
	for(int i=2;i<=50;i++){
		p2[i]=p2[i-1]*p2[i-1];
		p2[i] %= inf;
	}
	for(int i=1;i<=50;i++){
		if(k%2==1){
			res *= p2[i];
			res %= inf;
		}
		k /= 2;
	}
	return res;
}
signed main(){
	int n;
	string str;
	cin>>n>>str;
	int s=str.size();
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] += dp[i-1][j+1];
			dp[i][j] %= inf;
			if(j!=0){ dp[i][j] += 2*dp[i-1][j-1]; dp[i][j] %= inf;}
			else{ dp[i][j] += dp[i-1][j]; dp[i][j] %= inf;}
		}
	}
	int res = modpow((ll)2,(ll)inf-2);
	res = modpow(res,s);
	res *= dp[n][s];
	res %= inf;
	cout<<res<<endl;
	return 0;
}