#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
ll dp[100005][10];
int a[100005]; int b[100005];
int main(){
	int n;cin>>n;
	b[1] = 0;
	for(int i=0;i<2*n-1;i++){
		if(i%2==0) cin>>a[(i/2)+1];
		else{
			string s;cin>>s;
			b[(i+1)/2+1] = (s[0]=='-'?1:0);
		}
	}
	//cout<<a[1]<<a[2]<<a[3]<<b[1]<<b[2]<<b[3]<<endl;
	rep(i,100005) rep(j,10) dp[i][j]=-1e18;
	dp[0][0] = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++){
			if(dp[i][j]<-1e17) continue;
			if( (j+b[i+1])%2 == 0 ){
				for(int k=0;k<=j;k++) dp[i+1][k] = max(dp[i+1][k],dp[i][j]+a[i+1]);
				if(b[i+1]==1&&j!=9) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+a[i+1]);
			}
			else{
			    //if(i==1&&j==0)cout<<"N"<<endl;
				for(int k=0;k<=j;k++) dp[i+1][k] = max(dp[i+1][k],dp[i][j]-a[i+1]);
				if(b[i+1]==1&&j!=9) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]-a[i+1]);
			}
		}
	}//cout<<dp[4][1]<<endl;
	ll res = -1e18;
	rep(j,10) res = max(res,dp[n][j]);
	cout<<res<<endl;
}