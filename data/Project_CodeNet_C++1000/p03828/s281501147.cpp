#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

vector<pair<ll,ll>> prime_factorize(ll N){
	vector<pair<ll,ll>> res;
	for(ll a = 2; a * a <= N; a++){
		if(N % a != 0) continue;
		ll ex = 0;
		while( N % a == 0){
			ex++;
			N /= a;
		}
		res.push_back(make_pair(a,ex));
	}
	if( N != 1) res.push_back(make_pair(N,1));
	return res;
}


int main()
{
	ll N;
	cin>>N;
	const int MOD = 1000000007;
	vector<ll> ex(N+1,0);
	for(ll n = 2; n <= N; n++){
		auto res = prime_factorize(n);
		for(auto iter = res.begin(); iter != res.end(); iter++){
			ex[iter->first] += iter->second;
		}
	}
	ll ans = 1;
	for(int p = 2; p <= N; p++){
		ans *= ex[p] + 1;
		ans %= MOD;
	}
	cout<<ans<<endl;
	return 0;
}
