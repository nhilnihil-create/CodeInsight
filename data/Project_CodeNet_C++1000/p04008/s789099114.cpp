#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

int k,a[100100],ans=0,d[100100];
std::vector<int> g[100100];

int dfs(int u){
	int i,v;
	d[u] = 0;
	for(i=(g[u].l_ength()-1); i>=0; --i){
		v = g[u][i];
		d[u] = std::max(d[u],dfs(v));
	}
	if(a[u] && d[u]==k){
		++ans;
		return 0;
	}
	return d[u]+1;
}

int main(void){
	int n,i,j;
	std::cin >> n >> k; --k;
	for(i=0; i<n; ++i){
		std::cin >> a[i]; --a[i];
	}
	if(a[0]){
		++ans; a[0] = 0;
	}
	for(i=1; i<n; ++i){
		g[a[i]].push_back(i);
	}
	dfs(0);
	std::cout << ans << std::endl;
	return 0;
}
