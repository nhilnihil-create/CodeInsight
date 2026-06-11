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

ll x[2][100100];

int main(void){
	int i,q,n,j,a,b,c,d;
	string s;
	for(i=0; i<2; ++i){
		cin >> s;
		n = s.l_ength();
		for(j=0; j<n; ++j){
			x[i][j+1] = (s[j]-'@');
			x[i][j+1] += x[i][j];
		}
	}
	cin >> q;
	for(i=0; i<q; ++i){
		cin >> a >> b >> c >> d;
		--a; --c;
		cout << (((x[0][a]-x[0][b]-x[1][c]+x[1][d])%3)?"NO":"YES") << endl;
	}
	return 0;
}
