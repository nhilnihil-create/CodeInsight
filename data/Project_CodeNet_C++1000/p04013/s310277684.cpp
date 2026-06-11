#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
long long dp[60][60][2551];
int main(){
	dp[0][0][0]=1;
	int n,a,x[60],i,j,k;
	cin>>n>>a;
	for(i=0;i<n;i++) scanf("%lld",x+i);
	for(i=1;i<=n;i++){
		for(j=i;j>=0;j--){
			for(k=a*n+1;k>=0;k--){
				dp[i][j][k]+=dp[i-1][j][k];
                if(k>=x[i-1] && j>=1)
                    dp[i][j][k]+=dp[i-1][j-1][k-x[i-1]];
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++) ans+=dp[n][i][a*i];
	printf("%lld",ans);
	return 0;
}