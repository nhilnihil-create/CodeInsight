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

int a[100100];
ll b[100100];

int main(void){
	int n,i,k;
	ll ans=0ll,tmp=0ll;
	cin >> n >> k;
	for(i=0; i<n; ++i){
		cin >> a[i] >> b[i];
		if((a[i]|k)==k){
			ans += b[i];
		}
	}
	while(k){
		--k;
		tmp = 0ll;
		for(i=0; i<n; ++i){
			if((a[i]|k)==k){
				tmp += b[i];
			}
		}
		++k;
		k -= (k&-k);
		ans = max(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}
