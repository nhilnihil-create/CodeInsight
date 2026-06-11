
#include<bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	long int n,a;
	cin>>n>>a;
	
	long long int sum  = 0;
	long long int dp[55][2507];
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	int temp;
	
	for(int i=1;i<=n;i++){
			cin>>temp;
			for(int j=i;j>0;j--){
					for(int k=temp;k<=2500;k++){
							dp[j][k] += dp[j-1][k-temp];
					}
			}
	}
	
	for(int i=1;i<=n;i++)
		sum += dp[i][a*i];
		
	cout<<sum;
} 
