#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;

template <class T>
using lim = numeric_limits<T>;

const int N = 40;
const int AB = 10;

int dp[N+1][N*AB+1][N*AB+1];
int main() {
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	
	int n, ma, mb;
	cin >> n >> ma >> mb;
	
	// initialize to max
	// memset doesn't work for some reason
	for (int i = 0; i <= n; i++){
		for (int j =  0; j <= N*AB; j++){
			for (int k = 0; k <= N*AB; k++){
				dp[i][j][k] = lim<int>::max();
			} 
		}
	}

	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++){
		int ta, tb, tc;
		cin >> ta >> tb >> tc;
		for (int j = 0; j <= N*AB-ta; j++){
			for (int k = 0; k <= N*AB-tb; k++){
				if (dp[i][j][k] == lim<int>::max()) continue;
				dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
				dp[i+1][j+ta][k+tb] = min(dp[i+1][j+ta][k+tb],dp[i][j][k]+tc);
			}
		} 
	}
	
	int ans = lim<int>::max();
	for (int j = 1; j <= N*AB; j++){
		for (int k = 1; k <= N*AB; k++){
			if (j*mb == k*ma) {
				ans = min(ans, dp[n][j][k]);
			}
		}
	}
	
	cout << (ans==lim<int>::max() ? -1 : ans) << endl;
} 
