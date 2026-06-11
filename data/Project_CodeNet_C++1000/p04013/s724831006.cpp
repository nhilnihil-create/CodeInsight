#include <bits/stdc++.h>
#define LL long long int
using namespace std;

LL dp[55][2600];

int main(){
	memset(dp,0,sizeof(dp));
	int n,a,tmp;
	cin>>n>>a;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		for(int j=i;j>=1;j--){
			for(int k=0;k<=2500;k++){
				dp[j][k+tmp]+=dp[j-1][k];
			}
		}
	}
	
	LL ans=0;
	for(int i=1;i<=n;i++) ans+=dp[i][i*a];
	cout<<ans<<endl;
	return 0;
} 