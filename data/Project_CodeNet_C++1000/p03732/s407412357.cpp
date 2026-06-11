#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int N,W;
	cin>>N>>W;
	
	vector<int> w(N),v(N);
	
	for(int i=0;i<N;i++){
		cin>>w[i]>>v[i];
	}
	
	int w0 = w[0];
	
	for(int i=0;i<N;i++){
		w[i]-=w0;
	}
	
	int maxi = 3000;
	
	vector<vector<vector<int>>> dp(N+1,vector<vector<int>> (N+1,vector<int>(301,-1)));
	
	dp[0][0][0]=0;
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			for(int k=0;k<=300;k++){
				if(dp[i][j][k]==-1)continue;
				if(i!=N)dp[i+1][j][k]=max(dp[i][j][k],dp[i+1][j][k]);
				if(j!=N)dp[i][j+1][k]=max(dp[i][j][k],dp[i][j+1][k]);
				if(k!=300){
					dp[i][j][k+1] = max(dp[i][j][k],dp[i][j][k+1]);
				}
				int new_w = k+w[i];
				if(new_w>300||i==N||j==N)continue;
				dp[i+1][j+1][new_w] = max(dp[i][j][k] + v[i],dp[i+1][j+1][new_w]);
			}
		}
	}
	
	int ans = 0;
	
	for(int i=0;i<=N;i++){
		long long K = (long long)W - (long long)w0 * i;
		if(K<0)continue;
		if(K>300)K=300;
		ans = max(ans,dp[N][i][K]);
	}
	
	cout<<ans<<endl;
	
	
	
	
    return 0;
}

