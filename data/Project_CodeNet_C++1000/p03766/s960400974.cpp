#include<bits/stdc++.h>
#define maxn 1000005
#define Mod 1000000007
#define Val(x) (((long long)x) % Mod)
using namespace std;
int dp[maxn];
int cal(int n) {
	return Val((1 + n - 1) * (n-1) / 2);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	int sum = 0 , coe = 0;
	for(int i=1;i<=n;i++) {
		dp[i] = Val(sum + 1);
		coe = Val(coe + dp[i-2]);
		sum = Val(sum + coe);
	}
		
	int ans = Val(dp[n] * (n-1) + 1);
	for(int i=1;i<n;i++)
		ans = Val(Val(dp[i] * (n-1)) * n + ans);
	cout << ans << endl;
	return 0;
}
