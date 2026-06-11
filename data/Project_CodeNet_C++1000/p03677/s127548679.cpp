#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using ll = long long int;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

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

int a[100100];
std::vector<int> v[100100],u[100100];

int main(void){
	int n,m,i,j;
	ll ans = 0ll, tmp = 0ll, on = 0ll;
	std::cin >> n >> m;
	for(i=0; i<n; ++i){
		std::cin >> a[i]; --a[i];
	}
	for(i=1; i<n; ++i){
		if(a[i-1]>a[i]){
			ans += m;
			tmp -= (m-a[i-1]);
			++on;
		}
		ans += (a[i]-a[i-1]);
		v[a[i-1]].push_back(i);
		u[a[i]].push_back(i);
	}
	tmp += ans;
	for(i=0; i<m; ++i){
		ans = std::min(ans,tmp+on);
		for(j=(u[i].l_ength()-1); j>=0; --j){
			--on;
			tmp += (a[u[i][j]]-a[u[i][j]-1]+m)%m;
		}
		for(j=(v[i].l_ength()-1); j>=0; --j){
			++on;
		}
		tmp -= on;
	}
	std::cout << ans << std::endl;
	return 0;
}
