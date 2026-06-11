#include <bits/stdc++.h>
using namespace std;

int n,ma,mb;
int A[41],B[41],C[41];
int dp[41][401][401];

int main(){
	cin>>n>>ma>>mb;
	for(int i=1;i<=n;i++){
		cin>>A[i]>>B[i]>>C[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=400; j++){
			for(int k=0;k<=400;k++){
				dp[i][j][k]=100000000;
			}
		}
	}
	dp[0][0][0]=0;
	for(int i=1; i<=n;i++){
		for(int a=0;a<=400;a++){
			for(int b=0;b<=400;b++){
				if(dp[i-1][a][b]!=100000000){
					dp[i][a][b]=min(dp[i-1][a][b],dp[i][a][b]);
					dp[i][a+A[i]][b+B[i]]=min(dp[i-1][a][b]+C[i],dp[i][a+A[i]][b+B[i]]);
				}
			}
		}
	}
	int ans=100000000;
	for(int i=1;i<=400;i++){
		for(int j=1;j<=400;j++){
			if(i*mb==j*ma){
				ans=min(ans,dp[n][i][j]);
			}
		}
	}
	if(ans==100000000){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
}