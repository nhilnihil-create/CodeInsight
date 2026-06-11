#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 405;
const int inf = 5e7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, ma, mb;
	cin>>n>>ma>>mb;
	vector<vector<int> > dp[n + 1];
	for(int i = 0; i <= n; i++){
		dp[i] = vector<vector<int> >(N, vector<int>(N, inf));
	}
	dp[0][0][0] = 0;
	for(int i = 1; i <= n; i++){
		int a, b, c;
		cin>>a>>b>>c;
		for(int sa = 0; sa < N; sa++){
			for(int sb = 0; sb < N; sb++){
				dp[i][sa][sb] = min(dp[i][sa][sb], dp[i - 1][sa][sb]);
				if(sa + a < N && sb + b < N){
					dp[i][sa + a][sb + b] = min(dp[i][sa + a][sb + b], dp[i - 1][sa][sb] + c);
				}
			}
		}
	}
	int ans = inf;
	for(int k = 1; k*ma < N && k*mb < N; k++){
		ans = min(ans, dp[n][ma*k][mb*k]);
	}
	if(ans < inf)cout<<ans<<'\n';
	else cout<<-1<<'\n';


	return 0;
}