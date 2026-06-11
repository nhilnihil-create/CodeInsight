#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



i64 n, a[2020], x;
i64 dp[2020][2020];
void solve(){
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		dp[i][0] = a[i];
	}
	
	i64 ans = LINF;
	for(int i = 0; i < n; i++){
		i64 cnt = i*x;
		for(int j = 0; j < n; j++){
			cnt += dp[j][i];
			dp[j][i+1] = min(dp[j][i], a[mod(j-i-1,n)]);
		}
		chmin(ans,cnt);
	}
	cout << ans << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}