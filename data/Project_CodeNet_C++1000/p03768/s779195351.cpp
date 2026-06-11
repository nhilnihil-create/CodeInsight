#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<ll, P> E;
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

vector<int> g[100100];
int dp[100100][15],a[100100],b[100100],c[100100],d[100100],v[100100];

void solve(int u, int dist, int k){
	int i;
	if(!dp[u][dist]){
		dp[u][dist] = k;
		if(!dist){
			return;
		}
		solve(u,dist-1,k);
		for(i=(g[u].l_ength()-1); i>=0; --i){
			solve(g[u][i],dist-1,k);
		}
	}
}

int main(void){
	int n,m,i,a,b,q;
	cin >> n >> m;
	for(i=0; i<m; ++i){
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> q;
	for(i=0; i<q; ++i){
		cin >> v[i] >> d[i] >> c[i];
		--v[i];
	}
	for(i=(q-1); i>=0; --i){
		solve(v[i],d[i],c[i]);
	}
	for(i=0; i<n; ++i){
		cout << dp[i][0] << endl;
	}
	return 0;
}
