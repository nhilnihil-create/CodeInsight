#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;
ll dp[55][3][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	memset(dp, 0, sizeof(dp));
	int n; cin>>n;
	vector<string> s(2);
	cin>>s[0]>>s[1];
	if(s[0][0] == s[1][0]){
		for(int i = 0; i < 3; i++){
			dp[0][i][i] = 1;
		}
	}else{
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(i != j)dp[0][i][j] = 1;
			}
		}
	}
	for(int i = 1; i < n; i++){
		for(int p0 = 0; p0 < 3; p0++){
			for(int p1 = 0; p1 < 3; p1++){
				for(int c0 = 0; c0 < 3; c0++){
					for(int c1 = 0; c1 < 3; c1++){
						if((s[0][i] == s[1][i])^(c0 == c1))continue;
						if((s[0][i] == s[0][i - 1])^(c0 == p0))continue;
						if((s[1][i] == s[1][i - 1])^(c1 == p1))continue;
						dp[i][c0][c1] += dp[i - 1][p0][p1];
						if(dp[i][c0][c1] >= mod)dp[i][c0][c1] -= mod;
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			ans += dp[n - 1][i][j];
			if(ans >= mod)ans -= mod;
		}
	}
	cout<<ans<<'\n';

	return 0;
}