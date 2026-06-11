#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<ll, string> P;
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

int main(void){
	ll n,m,i,j,x[123456],y[123456],xsum=0ll,ysum=0ll,t;
	cin >> n >> m;
	for(i=0ll; i<n; ++i){
		cin >> x[i];
	}
	for(j=0ll; j<m; ++j){
		cin >> y[j];
	}
	for(i=1ll; i<n; ++i){
		t = x[i] - x[i-1];
		mul_mod(t,i);
		mul_mod(t,n-i);
		add_mod(xsum,t);
	}
	for(j=1ll; j<m; ++j){
		t = y[j] - y[j-1];
		mul_mod(t,j);
		mul_mod(t,m-j);
		add_mod(ysum,t);
	}
	cout << ((xsum*ysum)%MOD) << endl;
	return 0;
}
