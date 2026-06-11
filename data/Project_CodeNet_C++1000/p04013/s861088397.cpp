#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n,A; cin>>n>>A;
	int x[n];
	for(int i = 0; i < n; i++){
		cin>>x[i];
	}
	
	//int dp[n+1][n+2][A*n+1]; 
	//dp[a][b][c] ->a種類までのx[i]で、b個使い、合計cを作成する通り数。 
	long long (*dp)[n+2][n*A+1] = (long long(*)[n+2][n*A+1])malloc((n+1)*(n+2)*(A*n+1)*sizeof(long long));
	memset(dp,0,sizeof(dp));
	for(int i = 0; i < n+1; i++){
		dp[i][0][0] = 1;
		dp[0][i][0] = 0;
	}
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int s = 1; s <= i+1; s++){
			for(int j = 0; j <= A*n; j++){
				if(j < x[i]) dp[i+1][s][j] = dp[i][s][j];
				else dp[i+1][s][j] = dp[i][s][j]+dp[i][s-1][j-x[i]];
			}
		}
	}
	/*
	cout<<"\n"<<endl;
	for(int i = 0; i <= n; i++){
		for(int s = 1; s <= i; s++){
			for(int j = 0; j < n*A+1; j++){
				cout<<dp[i][s][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"\n"<<endl;
	}
	cout<<"\n"<<endl;
	*/
	long long ans = 0;
	for(int i = 1; i < n+1; i++){
		ans+=dp[n][i][i*A];
	}
	cout<<ans<<endl;
	return 0;
}