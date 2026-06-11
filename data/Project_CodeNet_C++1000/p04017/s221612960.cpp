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

int db[100100][25];
ll x[100100];

int main(void){
	int n,i,j=0,q,a,b,ans,tmp;
	ll l;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> x[i];
	}
	cin >> l;
	for(i=0; i<n; ++i){
		while(j+1<n && x[j+1]-x[i]<=l){
			++j;
		}
		db[i][0] = j;
	}
	for(j=0; j<20; ++j){
		for(i=0; i<n; ++i){
			db[i][j+1] = db[db[i][j]][j];
		}
	}
	cin >> q;
	for(i=0; i<q; ++i){
		cin >> a >> b; --a; --b;
		if(a>b){
			swap(a,b);
		}
		ans = INF;
		tmp = 0;
		for(j=20; j>=0; --j){
			if(db[a][j]>=b){
				ans = min(ans,tmp+(1<<j));
			}else{
				tmp += (1<<j);
				a = db[a][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
