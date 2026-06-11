#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55,M=1e3+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n,A,B;
int a[N],b[N],c[N];
int dp[M][M];
int main(){
	cin>>n>>A>>B;
	int sa=0,sb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		sa+=a[i],sb+=b[i];
	}
	mst(dp,0x3f);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=sa;j>=a[i];j--)
		{
			for(int k=sb;k>=b[i];k--){
				dp[j][k]=min(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
			}
		}
	}
	int ans=inf;
	for(int i=A,j=B;i<=sa&&j<=sb;i+=A,j+=B){
		ans=min(ans,dp[i][j]);
	} 
	if(ans==inf)puts("-1");
	else cout<<ans<<endl;
}