#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
using namespace std;
typedef pair<int,int> P;

signed main(){
	int n,W;
	cin>>n>>W;
	vector<int> w(n),v(n);
	rep(i,n) cin>>w[i]>>v[i];
	int M=w[0]-1;
	rep(i,n) w[i]-=M;
	int a=min(1LL*400,W);
	
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(a+1,vector<int>(n+1,0)));
	int ans=0;
	rep(i,n){ 
		rep(j,a+1){
			if(j-w[i]>=0){
				rep(k,n){
					int p=dp[i][j-w[i]][k];
					dp[i+1][j][k+1]=max(dp[i][j][k+1],p+v[i]);
				}
			}
			else dp[i+1][j]=dp[i][j];
			//cout<<dp[i+1][j].first<<" \n"[j==a];
		}
		rep(j,a+1) rep(k,n+1){
			if(W-k*M-j>=0) ans=max(dp[n][j][k],ans);
		}
	}
	cout<<ans<<endl;
}