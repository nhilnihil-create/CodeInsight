#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	int N; cin >> N;
	const LL mod = 1e9+7;
	vector<LL> dp(N+1,1);
	dp[1] = N;
	LL s = N+1;
	repp(i,1,N){
		dp[i+1] = ((LL)(N-1)*(N-1)+s-dp[i-1]+N-i)%mod;
		s = (s+dp[i+1])%mod;
	}
	cout << (dp[N]+mod)%mod << endl;
	return 0;
}
