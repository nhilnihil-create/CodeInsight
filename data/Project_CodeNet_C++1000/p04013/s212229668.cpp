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
int a[N],n,k;
ll dp[N][3000],ans;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	 dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
		for(int k=2500;k>=a[i];k--) dp[j][k]+=dp[j-1][k-a[i]];
	for(int i=1;i<=n;i++) ans+=dp[i][i*k];
		printf("%lld\n",ans);
	return 0;
}