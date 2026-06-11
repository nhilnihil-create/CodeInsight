#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 55;
const int M = 2555;

ll dp[N][M];
int arr[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, A;
	cin>>n>>A;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int k = n - 1; k >= 0; k--){
			for(int sum = 0; sum + arr[i] < M;  sum++){
				dp[k + 1][sum + arr[i]] += dp[k][sum];
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans += dp[i][A*i];
	}
	cout<<ans<<endl;

	return 0;
}