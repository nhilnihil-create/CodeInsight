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

int main(void){
	int n,i;
	ll a,p=1ll,ans=0ll;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a;
		ans += (a-1)/p;
		if((a-1)/p){
			a = 1ll;
		}
		if(a==p){
			++p;
		}
	}
	cout << ans << endl;
	return 0;
}
