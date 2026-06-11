#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define gt first
#define gc second.first
#define gr second.second
#define MOD (1000000007ll)
#define l_ength size
#define PI 3.14159265358979

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

int ufr[2][225816],ufp[2][225816];

void ufinit(int n, int t){
	int i;
	for(i=0; i<n; ++i){
		ufr[t][i] = 0;
		ufp[t][i] = i;
	}
}

int ufind(int x, int t){
	if(x == ufp[t][x]){
		return x;
	}
	ufp[t][x] = ufind(ufp[t][x],t);
	return ufp[t][x];
}

void unionf(int x, int y, int t){
	x = ufind(x, t);
	y = ufind(y, t);
	if(ufr[t][x] < ufr[t][y]){
		ufp[t][x] = y;
	}else{
		ufp[t][y] = x;
	}
	if(ufr[t][x] == ufr[t][y]){
		++ufr[t][x];
	}
}

vector<ll> v;
ll g[225816];

int main(void){
	int k[2],i,j,n,p,q;
	cin >> n >> k[0] >> k[1];
	for(j=0; j<2; ++j){
		ufinit(n,j);
		for(i=0; i<k[j]; ++i){
			cin >> p >> q;
			--p; --q;
			unionf(p,q,j);
		}
	}
	for(i=0; i<n; ++i){
		g[i] = (ll)(ufind(i,0))*(ll)(n)+(ll)(ufind(i,1));
		v.push_back(g[i]);
	}
	sort(v.begin(),v.end());
	for(i=0; i<n; ++i){
		cout << ((i)?" ":"") << ((int)(upper_bound(v.begin(),v.end(),g[i])-lower_bound(v.begin(),v.end(),g[i])));
	}
	cout << endl;
	return 0;
}
