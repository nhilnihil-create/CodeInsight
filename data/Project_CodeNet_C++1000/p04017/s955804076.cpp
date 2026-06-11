#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000007
#define LINF 1000000000000000007
 
typedef long long i64;
typedef pair<i64,i64> P;


i64 n, m, q, x[101010], ans[101010];
i64 dp[33][101010];

i64 dfs(int a, int b, i64 c){
	
	for(int i = 29; i > 0; i--){
		if(dp[i][a] < b){
			return dfs(dp[i][a], b, c+(1 << i));
		}
	}
	if(dp[0][a] >= b){
		return c + 1;
	}
	else return c + 2;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i];
	cin >> m >> q;
	
	for(int i = 0; i < n; i++){
		dp[0][i] = (upper_bound(x, x+n, x[i]+m)-1) - x;
	}
	int cnt = 0;
	for(int k = 2; k < INF; k*=2){
		cnt++;
		for(int i = 0; i < n; i++){
			if(dp[cnt-1][i] == dp[cnt-1][dp[cnt-1][i]]) dp[cnt][i] = INF;
			dp[cnt][i] = dp[cnt-1][dp[cnt-1][i]];
		}
	}
	
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		
		ans[i] = dfs(a-1,b-1,0);
	}
	for(int i = 0; i < q; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}