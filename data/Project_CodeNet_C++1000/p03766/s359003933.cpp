#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 1000003

long long n, sum;
long long dp[mx];

int main(){
	cin >> n;
	for(int i = n; i > 0; i--){
		long long &ret = dp[i];
		// debug(i);
		ret = 0;
		if(i == n){
			ret = n;
			sum = (sum + n) % MOD;
			// debug(ret);
			continue;
		}
		if(i == n - 1){
			ret = n * n % MOD;
			sum = (sum + ret) % MOD;
			// debug(ret);
			continue;
		}
		// naruh angka < n - i terus 1
		ret = sum;
		ret = (ret - dp[i + 2]) % MOD;
		ret = (ret + MOD) % MOD;
		// debug(ret);
		//naruh angka >= n - i terus bebas
		ret = (ret + (i + 1) * n) % MOD;
		// debug(ret);
		//naruh 1 < angka < n - i  terus selain 1
		ret = (ret + (n - i - 2) * (n - 1)) % MOD;
		sum = (sum + ret) % MOD;
		// debug(ret);
	}
	cout << dp[1] << endl;
}