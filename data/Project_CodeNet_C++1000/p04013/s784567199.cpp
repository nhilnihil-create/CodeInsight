#include <bits/stdc++.h>
using namespace std;

#define ll long long

int x[55];
ll	dp[55][55][2700];
int main() {

	int n, a;
	cin>>n>>a;
	
	for(int i=1; i<=n; i++) cin>>x[i];
	
	
	for(int i=0; i<=n; i++)
		dp[i][0][0]=1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			for(int s=1; s<=2600 ; s++){
				 if(j==1 && x[i]==s) dp[i][j][s]=1LL;
				 if(x[i]>s) dp[i][j][s]=dp[i-1][j][s];
				else if(s>=x[i]) dp[i][j][s] = dp[i-1][j-1][s-x[i]] + dp[i-1][j][s];

				}
			
			}
		
		}
	
	 ll ans=0LL;	
	for(int i=1; i<=n; i++){
		ans+=dp[n][i][i*a];
		}	
		
		cout<<ans<<endl;
		
		//for(int i=0; i<=n; i++)
		//for(int j=0; j<=n; j++)
			//for(int s=0; s<=30 ; s++){
				
				//cout<<i<<" "<<j<<" "<<s<<" "<<dp[i][j][s]<<endl;
				//}
	
	return 0;
}
