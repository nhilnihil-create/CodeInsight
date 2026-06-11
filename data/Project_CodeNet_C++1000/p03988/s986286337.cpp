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

int c[123];

int main(void){
	int a,n,i,r=-INF,d;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a;
		++c[a];
		r = max(r,a);
	}
	for(i=0; i<=r; ++i){
		d = max(i,r-i);
		if(!c[d]){
			cout << "Impossible" << endl;
			return 0;
		}
		--c[d];
	}
	for(i=1; i<r; ++i){
		d = max(i,r-i)+1;
		c[d] = 0;
	}
	for(i=0; i<=r; ++i){
		if(c[i]){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
	return 0;
}
