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

ll x[100100],ans=1ll;

int main(void){
	int i,n;
	ll cnt=1ll;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> x[i];
	}
	if(x[0]>1ll){
		x[0] = 1ll;
	}
	for(i=1; i<n; ++i){
		++cnt;
		if(x[i]-x[i-1]==1ll){
			mul_mod(ans,cnt);
			--x[i];
			--cnt;
		}
		x[i] = min(x[i],x[i-1]+2);
	}
	while(cnt){
		mul_mod(ans,cnt);
		--cnt;
	}
	cout << ans << endl;
	return 0;
}
