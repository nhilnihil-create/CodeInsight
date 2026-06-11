#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
int n;
ll dp[3], a, b, c, d;
char o;
int main(){
	scanf("%d%lld", &n, dp);
	dp[1] = dp[2] = -1e15;
	rep(i,n-1){
		scanf(" %c %lld", &o, &a);
		b = dp[0]; c = dp[1]; d = dp[2];
		if(o == '+'){
			dp[0] = max({b, c, d}) + a;
			dp[1] = max(c, d) - a;
			dp[2] += a;
		}else{
			dp[0] = max({b, c, d}) - a;
			dp[1] = max(max(c, d) + a, b - a);
			dp[2] = max(c, d) + a;
		}
	}
	printf("%lld\n", max({dp[0], dp[1], dp[2]}));
}