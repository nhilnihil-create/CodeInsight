#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
int a[N];
ll dp[N][N][3000],pre[1005];
int main(){
	int n,k;
	cin>>n>>k;
	ll  ans=0,sum=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=0;i<=n;i++) dp[i][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
		for(int k=1;k<=pre[i];k++){
			if(k>=a[i])
			dp[i][j][k]+=dp[i-1][j-1][k-a[i]];
			dp[i][j][k]+=dp[i-1][j][k];
			//printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
		}
	}
	for(int i=1;i<=n;i++)
			ans+=dp[n][i][i*k];
		printf("%lld\n",ans);
	return 0;
}