#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

long long N, A, X[103], dp[103][10005];

int main(){
	scanf("%lld %lld", &N, &A);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &X[i]);
		X[i] -= A;
	}
	
	/*for (int i = 0; i < N; i++) {
	    printf("%lld\n", X[i]);
	}*/
	
	for (int i = 0; i < N; i++) {
	    if (i > 0) {
    	    for (int j = 1000; j < 7000; j++) {
    	        dp[i][j] = dp[i - 1][j];
    	    }
    	    for (int j = 1000; j < 7000; j++) {
    	        dp[i][X[i] + j] += dp[i - 1][j];    
    	    }
	    }
	    dp[i][X[i] + 3500]++;
	}
	/*for (int i = 0; i < 7000; i++) {
	    if (dp[N - 1][i] > 0) {
	        printf("%d %lld\n", i, dp[N - 1][i]);
	    }
	}*/
	
	printf("%lld\n", dp[N - 1][3500]);
	return 0;
}