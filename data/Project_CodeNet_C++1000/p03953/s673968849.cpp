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
	if(a>MOD){
		a -= MOD;
	}
}

ll x[100100],y[100100],z[100100];

int main(void){
	int n,i,m,a;
	ll k;
	cin >> n;
	vector<int> v(n),u(n);
	iota(v.begin(),v.end(),0);
	for(i=0; i<n; ++i){
		cin >> x[i];
	}
	for(i=1; i<n; ++i){
		y[i] = x[i]-x[i-1];
	}
	cin >> m >> k;
	for(i=0; i<m; ++i){
		cin >> a;
		swap(v[a-1],v[a]);
	}
	while(k){
		if(k%2){
			for(i=1; i<n; ++i){
				z[i] = y[v[i]];
			}
			for(i=1; i<n; ++i){
				y[i] = z[i];
			}
		}
		for(i=1; i<n; ++i){
			u[i] = v[i];
		}
		for(i=1; i<n; ++i){
			v[i] = u[u[i]];
		}
		k /= 2;
	}
	for(i=1; i<n; ++i){
		x[i] = x[i-1] + y[i];
	}
	for(i=0; i<n; ++i){
		cout << x[i] << endl;
	}
	return 0;
}
