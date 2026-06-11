#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
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

int memo[100100];
bool done[100100];
vector<int> v[100100],g[100100];

int solve(int p){
	int n,i;
	if(done[p]){
		return memo[p];
	}
	done[p] = true;
	memo[p] = 0;
	n = g[p].l_ength();
	for(i=0; i<n; ++i){
		v[p].push_back(solve(g[p][i]));
	}
	sort(v[p].begin(),v[p].end());
	for(i=0; i<n; ++i){
		memo[p] = max(memo[p],v[p][i]+n-i);
	}
	return memo[p];
}

int main(void){
	int n,i,a;
	cin >> n;
	for(i=1; i<n; ++i){
		cin >> a; --a;
		g[a].push_back(i);
	}
	cout << solve(0) << endl;
	return 0;
}
