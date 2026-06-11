#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 10005

int N;
int S[105];
bool dp[SIZE];

int main(){

	scanf("%d",&N);

	int sum = 0;

	for(int i = 0; i < N; i++){

		scanf("%d",&S[i]);
		sum += S[i];
	}

	for(int i = 0; i <= sum; i++){

		dp[i] = false;
	}
	dp[0] = true;

	for(int i = 0; i < N; i++){
		for(int k = sum; k-S[i] >= 0; k--){
			dp[k] |= dp[k-S[i]];
		}
	}

	int ans = 0;

	for(int i = 0; i <= sum; i++){
		if(i%10 == 0)continue;

		if(dp[i]){

			ans = i;
		}
	}

	printf("%d\n",ans);

	return 0;
}
