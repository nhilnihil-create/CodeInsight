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
	ll i,o,t,j,l,s,z,k=0;
	cin >> i >> o >> t >> j >> l >> s >> z;
	k = ((i/2)+(j/2)+(l/2))*2;
	if(i&&j&&l){
		--i; --j; --l;
		k = max(k,((i/2)+(j/2)+(l/2))*2+3);
	}
	k += o;
	cout << k << endl;
	return 0;
}
