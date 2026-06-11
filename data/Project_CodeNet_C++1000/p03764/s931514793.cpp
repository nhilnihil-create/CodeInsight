
#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };


#define MAXM 100010
vl fact(MAXM);
vl C(MAXM);

ll mod_pow(ll x, ll p, ll M) {
	ll a = 1;
	while (p) {
		if (p % 2)
			a = a*x%MOD;
		x = x*x%MOD;
		p /= 2;
	}
	return a;
}

ll mod_inverse(ll a, ll m) {
	return mod_pow(a, m - 2, m);
}

ll nCr(ll n, ll r) {
	ll ret = fact[n];
	ret = (ret*mod_inverse(fact[r], MOD)) % MOD;
	ret = (ret*mod_inverse(fact[n - r], MOD)) % MOD;
	return ret;
}


int main() {
	ll n, m, i, j;
	cin >> n >> m;
	
	fact[0] = fact[1] = 1LL;
	for (i = 2; i < max(n, m) + 1; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}

	vl x(n), y(m);
	for (i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (j = 0; j < m; j++) {
		cin >> y[j];
	}
	vl sx(n - 1);
	ll sumx = 0;
	for (i = 0; i < n - 1; i++) {
		sx[i] = x[i + 1] - x[i];
		sx[i] = sx[i] * (i + 1) % MOD * (n - i - 1) % MOD;
		(sumx += sx[i]) %= MOD;
	}

	vl sy(m - 1);
	ll ans = 0;
	for (i = 0; i < m - 1; i++) {
		sy[i] = y[i + 1] - y[i];
		sy[i] = sy[i] * (i + 1) % MOD * (m - i - 1) % MOD;
		(ans += sy[i] * sumx % MOD) %= MOD;
	}
	cout << ans << endl;
}