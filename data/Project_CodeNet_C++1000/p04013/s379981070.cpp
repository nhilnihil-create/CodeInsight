#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



ll N,A;
ll X[55];
ll dp[55][2505];


int main(){

	scanf("%lld %lld",&N,&A);

	for(int i = 0; i < N; i++){

		scanf("%lld",&X[i]);
	}

	for(int i = 0; i <= N; i++){
		for(int k = 0; k < 2505; k++){

			dp[i][k] = 0;
		}
	}


	dp[0][0] = 1;

	for(int i = 0; i < N; i++){
		for(int k = i; k >= 0; k--){
			for(int num = 0; num+X[i] < 2505; num++){
				if(dp[k][num] == 0)continue;

				dp[k+1][num+X[i]] += dp[k][num];
			}
		}
	}

	ll ans = 0;

	for(ll i = 1; i <= N && A*i < 2505; i++){

		ans += dp[i][A*i];
	}

	printf("%lld\n",ans);

	return 0;
}
