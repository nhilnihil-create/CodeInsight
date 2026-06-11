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

int segtree[1212121][2],m;

bool segflag[1212121];

void eval(int i, int l, int r){
	if(segflag[i]){
		segtree[i][0] += segtree[i][1] * (r-l);
		if(r-l>1){
			segtree[i*2+1][1] += segtree[i][1];
			segflag[i*2+1] = true;
			segtree[i*2+2][1] += segtree[i][1];
			segflag[i*2+2] = true;
		}
		segtree[i][1] = 0;
		segflag[i] = false;
	}
}

void update(int a, int b, int i=0, int l=0, int r=m){
	eval(i,l,r);
	if(r<=a || b<=l){
		return;
	}
	if(a<=l && r<=b){
		++segtree[i][1];
		segflag[i] = true;
		eval(i,l,r);
	}else{
		update(a,b,i*2+1,l,(l+r)/2);
		update(a,b,i*2+2,(l+r)/2,r);
		segtree[i][0] += segtree[i*2+1][0] + segtree[i*2+2][0];
	}
}

int query(int a, int b, int i=0, int l=0, int r=m){
	int lv,rv;
	eval(i,l,r);
	if(r<=a || b<=l){
		return 0;
	}
	if(a<=l && r<=b){
		return segtree[i][0];
	}else{
		lv = query(a,b,i*2+1,l,(l+r)/2);
		rv = query(a,b,i*2+2,(l+r)/2,r);
		return (lv+rv);
	}
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
			ans += query(i,i+1);
			// cout << d << " " << i << " " << query(i,i+1) << endl;
		}
		for(i=(v[d].l_ength()-1); i>=0; --i){
			--n;
			update(v[d][i].first,v[d][i].second);
			// cout << v[d][i].first << " " << v[d][i].second << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
