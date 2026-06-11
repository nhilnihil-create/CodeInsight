#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, k, a[5001], dp[2][5001];

bool noneed(ll nowi){
	for(ll i = 1; i <= k; i++){dp[0][i] = 0;}
	dp[0][0] = 1;
		
	for(ll i = 1; i <= n; i++){
		if(i != nowi){
			for(ll j = 0; j <= k; j++){dp[1][j] = 0;}
			
			for(ll j = 0; j <= k; j++){
				if(dp[0][j] == 1){
					dp[1][j] = 1;
					if(j+a[i] <= k){dp[1][j+a[i]] = 1;}
				}
			}
			for(ll j = 0; j <= k; j++){dp[0][j] = dp[1][j];}
		}
	}
	
	for(ll i = max((ll) 0, k-a[nowi]); i <= k-1; i++){
		if(dp[0][i] == 1){return false;}
	}
	return true;
}

int main() {
	cin >> n >> k;
	for(ll i = 1; i <= n; i++){cin >> a[i];}
	sort(a+1, a+n+1);
	
	ll ansmax = n+1;
	ll ansmin = 0;
	while(ansmin+1 != ansmax){
		ll mid = (ansmax+ansmin)/2;
		if(noneed(mid)){ansmin = mid;}
		else{ansmax = mid;}
		//cout << ansmin << endl;
	}
	
	cout << ansmin << endl;
	return 0;
}