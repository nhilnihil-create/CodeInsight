#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

ll a[100100];
bool done[100100],ans[100100];
vector<int> g[100100];

ll solve(int u){
	int i,v,c=0;
	ll s=0ll,m=-INFLL,t;
	done[u] = true;
	for(i=(g[u].l_ength()-1); i>=0; --i){
		v = g[u][i];
		if(done[v]){
			continue;
		}
		++c;
		t = solve(v);
		s += t;
		m = max(m,t);
		if(!ans[v]){
			ans[u] = false;
			return -INFLL;
		}
	}
	if(!c){
		ans[u] = true;
		return a[u];
	}else if(c==1){
		ans[u] = (s==a[u]);
		return a[u];
	}else if(a[u]*2<s || s<a[u] || m>a[u]){
		ans[u] = false;
		return (a[u]*2-s);
	}else{
		ans[u] = true;
		return (a[u]*2-s);
	}
}

int main(void){
	int n,u,v,i;
	ll x;
	fill(done,done+100100,false);
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	for(i=1; i<n; ++i){
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	x = solve(0);
	if(g[0].l_ength()>1 && x){
		ans[0] = false;
	}
	cout << ((ans[0])?"YES":"NO") << endl;
	return 0;
}
