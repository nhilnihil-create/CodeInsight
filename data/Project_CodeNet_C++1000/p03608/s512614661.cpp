#include <bits/stdc++.h>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

struct edge {
	ll ind;
	ll to;
	ll d;
};


///////////////////////////

void WF(ll N,  vector<vector<ll>> &g) {
	repn(k, N) {
		repn(i, N) {
			repn(j, N) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}


int main() {

    ll N,M,R;
    cin >>N>>M>>R;

    vector<ll> r(R+1);
    repn(i,R) cin >>r[i];

    vector<vector<ll>> g(N+1,vector<ll>(N+1,INF));

    repn(i,M){
        ll a,b,c;
        cin >>a>>b>>c;

        g[a][b]=c;
        g[b][a]=c;
    }

    WF(N,g);

    //repn(i,N)repn(j,N) cout <<g[i][j];

    ll ans=INF;

    vector<ll> v(R+1);
    repn(i,R) v[i]=i;

    do{
        ll d=0;
        repn(i,R-1) d+=g[r[v[i]]][r[v[i+1]]];
        ans=min(ans,d);
    }
    while(next_permutation(++v.begin(),v.end()));

    cout <<ans;


 
	

}
