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
	a += b;
	a %= MOD;
}

int bitree[2][334334],m;

int query(int i, int p){
	int v=0;
	while(p){
		v += bitree[i][p];
		p -= p&(-p);
	}
	return v;
}

void update(int i, int p, int v){
	int ret=0;
	while(p<=m){
		bitree[i][p] += v;
		p += p&(-p);
	}
}

void addtrain(int l, int r){
	update(0,l,1);
	update(0,r,-1);
	update(1,l,1-l);
	update(1,r,r-1);
}

int cnt(int p){
	int v;
	v = p*query(0,p)+query(1,p);
	--p;
	v -= (p*query(0,p)+query(1,p));
	return v;
}

vector<P> v[300300];

int main(void){
	int n,i,d,l,r,ans;
	cin >> n >> m; ++m;
	for(i=0; i<n; ++i){
		cin >> l >> r; ++r;
		v[r-l].push_back(P(l,r));
	}
	for(d=1; d<m; ++d){
		ans = n;
		for(i=d; i<m; i+=d){
			ans += cnt(i);
		}
		for(i=(v[d].l_ength()-1); i>=0; --i){
			--n;
			addtrain(v[d][i].first,v[d][i].second);
		}
		cout << ans << endl;
	}
	return 0;
}
