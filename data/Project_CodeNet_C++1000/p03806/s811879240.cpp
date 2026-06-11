#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int N;
	cin>>N;
	
	int M1,M2;
	cin>>M1>>M2;
	
	vector<pair<int,int>> V(N);
	vector<int> C(N);
	for(int i=0;i<N;i++){
		cin>>V[i].first>>V[i].second>>C[i];
	}
	
	vector<vector<int>> dp(N+1,vector<int>(200000,Inf));
	dp[0][0] = 0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<200000;j++){
			if(dp[i][j]==Inf)continue;
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			int a = j/400;
			int b = j%400;
			a+=V[i].first;
			b+=V[i].second;
			int c = a*400+b;
			dp[i+1][c] = min(dp[i+1][c],dp[i][j]+C[i]);
		}
	}
	
	int ans = Inf;
	for(int i=1;i<200000;i++){
		int a = i/400;
		int b = i%400;
		if(M1*b!=M2*a)continue;
		ans = min(ans,dp[N][i]);
	}
	
	if(ans==Inf){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	
    return 0;
}

