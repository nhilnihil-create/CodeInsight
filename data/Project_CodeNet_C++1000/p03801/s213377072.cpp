#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using ll = long long int;
using P = std::pair<ll, int>;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(2e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

P v[100100];
ll ans[100100];

int main(void){
	int n,i,x;
	ll a;
	std::cin >> n; x = n;
	for(i=0; i<n; ++i){
		std::cin >> a;
		v[i] = P(a,i);
	}
	v[n] = P(0ll,n);
	std::sort(v,v+n+1);
	for(i=n; i>0; --i){
		x = std::min(x,v[i].second);
		if(v[i].first != v[i-1].first){
			ans[x] += (v[i].first-v[i-1].first)*(n-i+1);
		}
	}
	for(i=0; i<n; ++i){
		std::cout << ans[i] << std::endl;
	}
	return 0;
}
