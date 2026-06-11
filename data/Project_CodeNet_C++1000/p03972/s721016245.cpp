#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
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

vector<P> v;

int main(void){
	int k,i,n[2],m=0,a[2];
	ll p,ans=0ll;
	cin >> n[0] >> n[1];
	for(k=0; k<2; ++k){
		a[k] = n[k]+1;
		m += n[k];
		for(i=0; i<n[k]; ++i){
			cin >> p;
			v.push_back(P(p,k));
		}
	}
	sort(v.begin(),v.end());
	for(i=0; i<m; ++i){
		p = v[i].first;
		k = v[i].second;
		ans += p*a[1-k];
		--a[k];
	}
	cout << ans << endl;
	return 0;
}
