#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const long long M = 1000000007;

//x^n mod M
typedef long long ull;
ull power(ull x, ull n){
	ull res = 1;
	if(n > 0){
		res = power(x, n / 2);
		if(n % 2 == 0) res = (res * res) % M;
		else res = (((res * res) % M) * x ) %M;
	}
	return res;
}

int main(){
	int n;
	string s;
	cin >> n >> s;

	vector<long long> dp(n + 1, 0);
	dp[0] = 1;
	rep(i,n){
		vector<long long> _dp(n + 2, 0);
		rep(j,n + 1){
			if(j == 0) (_dp[j] += dp[j]) %= M;
			else (_dp[j - 1] += dp[j]) %= M;
			(_dp[j + 1] += dp[j] * 2LL) %= M;
		}
		dp = _dp;
		//for(auto j : dp){ for(auto k : j){ cout << k <<  ' '; } cout << endl; } cout << endl;
	}
	cout << dp[s.size()] * power(power(2,s.size()), M - 2) % M  << endl;
}
