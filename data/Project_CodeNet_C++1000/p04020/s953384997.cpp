#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
const int inf = 1e8;
int A[N], dp[N][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		cin>>A[i];
		if(A[i]&1){
			ans += A[i]>>1;
			A[i] = 1;
		}else if(A[i] > 0){
			ans += (A[i]>>1) - 1;
			A[i] = 2;
		}
	}
	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = -inf;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 2; j++){
			dp[i][j] = -inf;
		}
		dp[i][A[i]] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
		if(A[i] == 2){
			dp[i][0] = max(dp[i][0], max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1);
		}
		if(A[i] > 0){
			dp[i][A[i] - 1] = max(dp[i][A[i] - 1], max({dp[i - 1][1], dp[i - 1][2]}) + 1);
		}
	}
	ans += max({dp[n][0], dp[n][1], dp[n][2]});
	cout<<ans<<'\n';

	return 0;
}