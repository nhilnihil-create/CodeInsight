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

int ufp[334334],ufr[334334];

void ufinit(int n){
	int i;
	for(i=0; i<n; ++i){
		ufp[i] = i;
		ufr[i] = 1ll;
	}
}

int ufind(int x){
	if(x == ufp[x]){
		return x;
	}
	ufp[x] = ufind(ufp[x]);
	return ufp[x];
}

bool unionf(int x, int y){
	x = ufind(x);
	y = ufind(y);
	if(x==y){
		return false;
	}
	if(ufr[x] < ufr[y]){
		swap(x,y);
	}
	ufp[y] = x;
	ufr[x] += ufr[y];
	return true;
}

int main(void){
	int n,m,i,u,v;
	ll ans,p,q=0ll,r=0ll;
	cin >> n >> m;
	p = n;
	ans = p*p;
	ufinit(n*3);
	for(i=0; i<m; ++i){
		cin >> u >> v;
		--u; --v;
		unionf(u,v);
		unionf(u+n,v+n*2);
		unionf(u+n*2,v+n);
	}
	for(i=0; i<n; ++i){
		if(ufind(i)!=i){
			continue;
		}
		if(ufr[i] == 1){
			--p;
		}else if(ufind(i+n)==ufind(i+n*2)){
			++q;
		}else{
			++r;
		}
	}
	ans -= p*p;
	ans += (q+r)*(q+r)+r*r;
	cout << ans << endl;
	return 0;
}
