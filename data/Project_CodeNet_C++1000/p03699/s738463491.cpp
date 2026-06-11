#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 105;
const int M = 10005;

bool dp[M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, x;
	cin>>n;
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	for(int i = 0; i < n; i++){
		cin>>x;
		for(int sum = M - 1; sum >= x; sum--){
			dp[sum] |= dp[sum - x];
		}
	}
	int ans = 0;
	for(int i = 0; i < M; i++){
		if(dp[i] && i%10 != 0)ans = i;
	}
	cout<<ans<<endl;;

	return 0;
}