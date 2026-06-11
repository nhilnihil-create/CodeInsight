#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 5, MOD = 1e9 + 7;

int suffix[N], dp[N];

int add(int a, int b){
	int res = (a + b) % MOD;
	if(res < 0)	res += MOD;
	return res;
}

int mult(int a, int b){
	ll res = (a * 1LL * b) % MOD;
	if(res < 0)	res += MOD;
	return res;
}

int main(){
	int n;
	cin>>n;
	dp[n] = suffix[n] = n;
	for(int i = n - 1; i >= 1; i--){
		dp[i] = add(add(i + 1, mult(n - 1, n - 1)), add(dp[i + 1], suffix[i + 3]));
		if(i == n - 1)	dp[i] = add(dp[i], -1);
		suffix[i] = add(suffix[i + 1], dp[i]);
	}
	cout<<dp[1]<<endl;
}