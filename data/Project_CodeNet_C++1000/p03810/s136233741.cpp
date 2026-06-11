#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	ll cnt = 0;
	REP(i,n) cnt += a[i] % 2 ? 0 : 1;
	if(cnt % 2) cout << "First" << endl;
	else {
		ll t = 0;
		bool upd = true;
		while(cnt == n - 1 && upd) {
			upd = false;
			REP(i,n) if(a[i] % 2) {
				if(a[i] == 1) break;
				upd = true;
				t++;
				a[i]--;
				ll g = a[0];
				REP(j,n) g = gcd(g, a[j]);
				REP(j,n) a[j] /= g;
				cnt = 0;
				REP(j,n) cnt += a[j] % 2 ? 0 : 1;
				break;
			}
		}
		if(cnt % 2 != t % 2) cout << "First" << endl;
		else cout << "Second" << endl;
	}
	return 0;
}
