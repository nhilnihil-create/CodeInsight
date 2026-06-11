#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);
const ll M = (ll)(1e10);

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

vector<int> g[100100];

int solve(int v, int p = -1){
	int i,u,ret=0;
	for(i=(g[v].l_ength()-1); i>=0; --i){
		u = g[v][i];
		if(u==p){
			continue;
		}
		ret ^= (solve(u,v)+1);
	}
	return ret;
}

int main(void){
	int n,i,x,y;
	cin >> n;
	for(i=1; i<n; ++i){
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout << (solve(0)?"Alice":"Bob") << endl;
	return 0;
}
