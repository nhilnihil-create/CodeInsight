#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define MAX 100002

int n;

long long int a[MAX];

char buf[2];

long long int dp[MAX][3];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
			dp[i][j] = LLONG_MIN;
		}
		if (i){
			scanf("%s", buf);
		}
		scanf("%lld", &a[i]);
		if (i){
			if (buf[0] == '-'){
				a[i] *= -1;
			}
		}
	}
	dp[0][0] = a[0];
	for (int i = 0; i+1 < n; i++){
		for (int j = 0; j < 3; j++){
			if (dp[i][j] == LLONG_MIN)continue;
			long long int val = 1;
			if (j % 2){
				val *= -1LL;
			}
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]+a[i+1]*val);
			val *= -1LL;
			if (j){
				dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + a[i+1] * val*-1LL);
			}
			if (j + 1 < 3&&a[i+1]<0){
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i+1] * val*-1LL);
			}
		}
	}
	long long int ans = dp[n-1][0];
	ans = max(ans, dp[n - 1][1]);
	ans = max(ans, dp[n - 1][2]);
	printf("%lld\n", ans);
	return 0;
}